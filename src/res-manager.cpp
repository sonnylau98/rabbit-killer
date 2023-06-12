#include "res-manager.h"

std::vector<sf::Texture> ResourceManager::loadTextures(const std::vector<std::string>& texturePaths) {
    std::vector<sf::Texture> textures;
    for (const auto& path : texturePaths) {
        sf::Texture texture;
        texture.loadFromFile(path);
        textures.push_back(texture);
    }
    return textures;
}
