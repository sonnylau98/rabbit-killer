#ifndef RES_MANAGER_H
#define RES_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class ResourceManager {
public:
    static std::vector<sf::Texture> loadTextures(const std::vector<std::string>& texturePaths);
};

#endif // RES_MANAGER_H
