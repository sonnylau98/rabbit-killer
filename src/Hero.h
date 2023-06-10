#include <SFML/Graphics.hpp>

class Hero{
 public:
  Hero();
  ~Hero();

  void init(std::string textureName, sf::Vector2f position, float mass);

  void update(float dt);
  void jump(float velocity);
  void move(float velocity);
  void down(float velocity);

  void applyGravity(float dt);
  void applyFraction(float dt);

  sf::Sprite getSprite();

 private:
  sf::Texture m_texture;
  sf::Sprite m_sprite;
  sf::Vector2f m_position;
  sf::Vector2f m_velocity;

  float m_mass;
  const float m_gravity = 200.0f;
  const float m_mu = 25.0f;

  bool m_grounded;
};
