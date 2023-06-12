#include "hero.h"
#include "res-manager.h"

Hero::Hero(const std::vector<std::string>& texturePathsRight, const std::vector<std::string>& texturePathsLeft, const sf::Vector2f& position, float mass)
  : m_position(position), m_velocity(0.0f, 0.0f), m_mass(mass), m_grounded(false), m_facingRight(false)
{
    m_texturesRight = ResourceManager::loadTextures(texturePathsRight);
    m_texturesLeft = ResourceManager::loadTextures(texturePathsLeft);
    m_sprite.setTexture(m_texturesRight[0]);
    m_sprite.setPosition(m_position);
    m_sprite.setOrigin(m_texturesRight[0].getSize().x / 2, m_texturesRight[0].getSize().y / 2);
}

Hero::~Hero() {
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

    m_textureChangeTimer += dt;
    if (m_textureChangeTimer >= m_textureChangeInterval) {
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturesRight.size();

        if (m_facingRight) {
            m_sprite.setTexture(m_texturesRight[m_currentTextureIndex]);
        }
        else {
            m_sprite.setTexture(m_texturesLeft[m_currentTextureIndex]);
        }

        m_textureChangeTimer = 0.0f;
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

sf::Sprite Hero::getSprite() const {
    return m_sprite;
}
