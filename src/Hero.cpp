#include "Hero.h"

Hero::Hero() {

}

Hero::~Hero() {

}

void Hero::init(std::vector<std::string> textureNames, sf::Vector2f position, float mass) {
  m_position = position;
  m_velocity = sf::Vector2f(0.0f, 0.0f);

  m_mass = mass;
  m_grounded = false;

  for (const auto& textureName : textureNames) {
    sf::Texture texture;
    texture.loadFromFile(textureName.c_str());
    m_textures.push_back(texture);
  }

  m_sprite.setTexture(m_textures[0]);
  m_sprite.setPosition(m_position);
  m_sprite.setOrigin(m_textures[0].getSize().x / 2, m_textures[0].getSize().y / 2);
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

  //m_currentTextureIndex = (m_currentTextureIndex + 1) % m_textures.size();
  //m_sprite.setTexture(m_textures[m_currentTextureIndex]);

  //
    m_textureChangeTimer += dt;
  if (m_textureChangeTimer >= m_textureChangeInterval) {
    m_currentTextureIndex = (m_currentTextureIndex + 1) % m_textures.size();
    m_sprite.setTexture(m_textures[m_currentTextureIndex]);
    m_textureChangeTimer = 0.0f; // Reset the timer
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

sf::Sprite Hero::getSprite() {
  return m_sprite;
}
