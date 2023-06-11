#include <SFML/Graphics.hpp>
#include "Hero.h"

sf::Vector2f viewSize(1024, 570);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Chicken Bro", sf::Style::Default);

sf::Texture skyTexture;
sf::Sprite skySprite;

Hero hero;

sf::Vector2f playerPosition;

bool playerMovingRight = false;
bool playerMovingLeft = false;

std::vector<std::string> heroTextures = {
    "../img/rabbit/1.png",
    "../img/rabbit/2.png",
    "../img/rabbit/3.png",
    "../img/rabbit/4.png",
    "../img/rabbit/5.png",
    "../img/rabbit/6.png",
    "../img/rabbit/7.png",
    "../img/rabbit/8.png",
    "../img/rabbit/9.png",
    "../img/rabbit/10.png",
    "../img/rabbit/11.png",
    "../img/rabbit/12.png",
    "../img/rabbit/13.png",
    "../img/rabbit/14.png",
    "../img/rabbit/15.png",
    "../img/rabbit/16.png",
    "../img/rabbit/17.png",
    "../img/rabbit/18.png",
    "../img/rabbit/19.png",
    "../img/rabbit/20.png",
    "../img/rabbit/21.png",
    "../img/rabbit/22.png",
    "../img/rabbit/23.png",
    "../img/rabbit/24.png"
};


void init()
{
  skyTexture.loadFromFile("../img/bg.jpg");
  skySprite.setTexture(skyTexture);
  skySprite.setPosition(0, 0);
  skySprite.setScale(1.0f, 1.0f);

  hero.init(heroTextures, sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.25f), 200);

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
