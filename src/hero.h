#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>
#include "res-manager.h"


class Hero {
public:
  Hero(const std::vector<std::string>& texturePathsRight, const std::vector<std::string>& texturePathsLeft,
       const std::vector<std::string>& attackTexturePathsRight, const std::vector<std::string>& attackTexturePathsLeft, const sf::Vector2f& position, float mass);
  ~Hero();

  sf::Sprite getSprite() const;

  void update(float dt);
  void jump(float velocity);
  void down(float velocity);
  void move(float velocity);
  void applyGravity(float dt);
  void attack();

private:
  sf::Sprite m_sprite;

  sf::Vector2f m_position;
  sf::Vector2f m_velocity;

  float m_mass;
  const float m_gravity = 200.0f;
  bool m_grounded;

  std::vector<sf::Texture> m_texturesRight;
  std::vector<sf::Texture> m_texturesLeft;
  std::vector<sf::Texture> m_attackTexturesRight;
  std::vector<sf::Texture> m_attackTexturesLeft;

  int m_currentTextureIndex = 0;
  float m_textureChangeTimer = 0.0f;
  const float m_textureChangeInterval = 0.025f;

  bool m_facingRight;

  bool m_attacking;
  float m_attackTimer;
  const float m_attackInterval = 0.025f;

  void setSpriteTexture(sf::Sprite& sprite, const sf::Texture& texture);

};

#endif
