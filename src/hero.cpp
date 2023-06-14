#include "hero.h"
#include "res-manager.h"


Hero::Hero(const std::vector<std::string>& texturePathsRight, const std::vector<std::string>& texturePathsLeft,
           const std::vector<std::string>& attackTexturePathsRight, const std::vector<std::string>& attackTexturePathsLeft, const sf::Vector2f& position, float mass)
    : m_position(position), m_velocity(0.0f, 0.0f), m_mass(mass), m_grounded(false), m_facingRight(false), m_attacking(false), m_attackTimer(0.0f)
{
    m_texturesRight = ResourceManager::loadTextures(texturePathsRight);
    m_texturesLeft = ResourceManager::loadTextures(texturePathsLeft);
    m_attackTexturesRight = ResourceManager::loadTextures(attackTexturePathsRight);
    m_attackTexturesLeft = ResourceManager::loadTextures(attackTexturePathsLeft);

    m_sprite.setPosition(m_position);

    setSpriteTexture(m_sprite, m_texturesRight[0]);
}

Hero::~Hero()
{
    // Clear attack textures
    m_attackTexturesRight.clear();
    m_attackTexturesLeft.clear();
}

sf::Sprite Hero::getSprite() const {
    return m_sprite;
}

void Hero::update(float dt) {
    m_position.y -= m_velocity.y * dt;
    m_position.x -= m_velocity.x * dt;
    m_sprite.setPosition(m_position);

    if (m_position.y >= 700 * 0.9f) {
        m_position.y = 700 * 0.9f;
        m_grounded = true;
        m_velocity.y = 0.0f;
    }

    if (!m_attacking) {
      m_textureChangeTimer += dt;
      if (m_textureChangeTimer >= m_textureChangeInterval) {
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturesRight.size();

        if (m_facingRight) {
          setSpriteTexture(m_sprite, m_texturesRight[m_currentTextureIndex]);
        }
        else {
          setSpriteTexture(m_sprite, m_texturesLeft[m_currentTextureIndex]);
        }

        m_textureChangeTimer = 0.0f;
      }
    }
    else if (m_attacking) {
        m_attackTimer += dt;

        if (m_attackTimer >= m_attackInterval) {
            m_currentTextureIndex = (m_currentTextureIndex + 1) % m_attackTexturesRight.size();

            if (m_facingRight) {
              setSpriteTexture(m_sprite, m_attackTexturesRight[m_currentTextureIndex]);
            }
            else {
              setSpriteTexture(m_sprite, m_attackTexturesLeft[m_currentTextureIndex]);
            }

            m_attackTimer = 0.0f;

            if (m_currentTextureIndex == int(m_attackTexturesRight.size() - 1)) {
                m_attacking = false;
                if (m_facingRight) {
                  setSpriteTexture(m_sprite, m_texturesRight[0]);
                }
                else {
                  setSpriteTexture(m_sprite, m_texturesLeft[0]);
                }
            }
        }
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

    if (velocity > 0) {
        m_facingRight = true;
    }
    else if (velocity < 0) {
        m_facingRight = false;
    }
}

void Hero::applyGravity(float dt) {
    m_velocity.y -= m_gravity * dt;
}

void Hero::attack()
{
  m_attacking = true;
  m_attackTimer = 0.0f;
  m_currentTextureIndex = 0;

  if (m_facingRight) {
    setSpriteTexture(m_sprite, m_attackTexturesRight[m_currentTextureIndex]);
  } else {
    setSpriteTexture(m_sprite, m_attackTexturesLeft[m_currentTextureIndex]);
  }
}

void Hero::setSpriteTexture(sf::Sprite& sprite, const sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}
