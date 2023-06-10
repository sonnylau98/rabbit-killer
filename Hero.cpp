#include "Hero.h"

Hero::Hero() {

}

Hero::~Hero() {

}

void Hero::init(std::string textureName, sf::Vector2f position, float mass) {

  m_position = position;
  m_velocity = sf::Vector2f(0.0f, 0.0f);

  m_mass = mass;
  m_grounded = false;

  m_texture.loadFromFile(textureName.c_str());
  m_sprite.setTexture(m_texture);
  m_sprite.setPosition(m_position);
  m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
  m_sprite.setScale(0.5f, 0.5f);
}

void Hero::update(float dt) {

  m_position.y -= m_velocity.y * dt;
  m_position.x -= m_velocity.x * dt;

  m_sprite.setPosition(m_position);

  if (m_position.y >= 570 * 0.8f) {
    m_position.y = 570 * 0.8f;
    m_grounded = true;
    m_velocity.y = 0.0f;
  }
}

void Hero::jump(float velocity) {
  if (m_grounded) {
    m_velocity.y = velocity;
    m_grounded = false;
  }
}

void Hero::down(float velocity) {
    m_velocity.y = -velocity;
}



void Hero::move(float velocity) {
    m_velocity.x = velocity;
}

void Hero::applyGravity(float dt) {
  m_velocity.y -= m_gravity * dt;
}

void Hero::applyFraction(float dt) {
  if(m_grounded) {
    if (m_velocity.x > 0) {
      m_velocity.x -= m_mu * m_gravity;
    }
    else if (m_velocity.x < 0) {
      m_velocity.x += m_mu * m_gravity;
    }
  }
}

sf::Sprite Hero::getSprite() {
  return m_sprite;
}
