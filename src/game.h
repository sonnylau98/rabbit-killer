#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "hero.h"

class Game {
public:
    Game();

    void run();

private:
    sf::Vector2f viewSize{ 1000, 700 };
    sf::RenderWindow m_window;
    sf::Texture skyTexture;
    sf::Sprite skySprite;
    Hero m_hero;
    bool playerMovingRight = false;
    bool playerMovingLeft = false;

    void updateInput();
    void update(float dt);
    void draw();
};

#endif
