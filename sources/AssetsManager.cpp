#include <AssetsManager.hpp>


sf::Texture & AssetsManager::useTexture(const std::string & fileLocation){

  std::string folder { "assets/" }; 
  std::string fullPath { folder + fileLocation };

  sf::Texture texture; 

  if (textures.find(fullPath) != textures.end()) {
        return textures[fullPath];
    }

  if(!texture.loadFromFile(fullPath)){
        throw std::invalid_argument("texture could not be found/loaded"); 
  }
 
texture.setSmooth(true);

textures[fullPath] = texture;

    return textures[fullPath];

} 

//sf::Music & AssetsManager::playBackgroundMusic(const std::string & fileLocation){

//}