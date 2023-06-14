#include "game.h"
#include "texture.h"
#include "res-manager.h"


Game::Game()
  : m_window(sf::VideoMode(viewSize.x, viewSize.y), "Rabbit Killer", sf::Style::Default),
    m_hero(heroTexturesRight, heroTexturesLeft, attackTexturesRight, attackTexturesLeft, sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.25f), 200)
{
  skyTexture.loadFromFile(backgroundTexture);
  skySprite.setTexture(skyTexture);
  skySprite.setPosition(0, 0);
  skySprite.setScale(0.8f, 0.8f);
}

void Game::updateInput()
{
  sf::Event event;

  while (m_window.pollEvent(event)) {
    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Up) {
        m_hero.jump(400.0f);
      }
      else if (event.key.code == sf::Keyboard::Down) {
        m_hero.down(400.0f);
      }
      else if (event.key.code == sf::Keyboard::Left) {
        playerMovingLeft = true;
      }
      else if (event.key.code == sf::Keyboard::Right) {
        playerMovingRight = true;
      }
      else if (event.key.code == sf::Keyboard::J) {
        m_hero.attack();
      }
      else if (event.key.code == sf::Keyboard::Escape) {
        m_window.close();
      }
    }
    else if (event.type == sf::Event::KeyReleased) {
      if (event.key.code == sf::Keyboard::Left) {
        playerMovingLeft = false;
      }
      else if (event.key.code == sf::Keyboard::Right) {
        playerMovingRight = false;
      }
    }
    else if (event.type == sf::Event::Closed) {
      m_window.close();
    }
  }
}

void Game::update(float dt)
{
  if (playerMovingLeft) {
    m_hero.move(300.0f);
  }
  else if (playerMovingRight) {
    m_hero.move(-300.0f);
  }
  else {
    m_hero.move(0.0f);
  }

  m_hero.applyGravity(dt);
  m_hero.update(dt);
}

void Game::draw()
{
  m_window.clear();
  m_window.draw(skySprite);
  m_window.draw(m_hero.getSprite());
}

void Game::run()
{
  sf::Clock clock;

  while (m_window.isOpen()) {
    updateInput();
    sf::Time dt = clock.restart();
    update(dt.asSeconds());
    draw();
    m_window.display();
  }
}
