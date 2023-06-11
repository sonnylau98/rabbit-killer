#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Texture.h"

sf::Vector2f viewSize(1024, 570);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Chicken Bro", sf::Style::Default);

sf::Texture skyTexture;
sf::Sprite skySprite;

Hero hero;

sf::Vector2f playerPosition;

bool playerMovingRight = false;
bool playerMovingLeft = false;


void init()
{
  skyTexture.loadFromFile("../img/bg.jpg");
  skySprite.setTexture(skyTexture);
  skySprite.setPosition(0, 0);
  skySprite.setScale(1.0f, 1.0f);

  hero.init(heroTexturesRight, heroTexturesLeft, sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.25f), 200);
}

void updateInput()
{
  sf::Event event;

  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Up) {
        hero.jump(400.0f);
      }
      else if (event.key.code == sf::Keyboard::Down) {
        hero.down(400.0f);
      }
      else if (event.key.code == sf::Keyboard::Left) {
        playerMovingLeft = true;
      }
      else if (event.key.code == sf::Keyboard::Right) {
        playerMovingRight = true;
      }
      else if (event.key.code == sf::Keyboard::Escape) {
        window.close();
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
      window.close();
    }
  }
}

void update (float dt) {
  if (playerMovingLeft) {
    hero.move(300.0f);
  }
  else if (playerMovingRight) {
    hero.move(-300.0f);
  }
  else {
    hero.move(0.0f);
  }

  hero.applyGravity(dt);
  hero.update(dt);
}

void draw()
{
   window.draw(skySprite);
   window.draw(hero.getSprite());
}

int main()
{
  sf::Clock clock;

  init();

  while (window.isOpen())
  {
    updateInput ();

    sf::Time dt = clock.restart();

    update(dt.asSeconds());

    draw();

    window.display();
  }

  return 0;
}
