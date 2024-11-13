#include <AssetsManager.hpp>


sf::Texture & AssetsManager::useTexture(const std::string & fileName){

  std::string folder { "assets/" }; 
  std::string fullPath { folder + fileName };

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

sf::Music & AssetsManager::playBackgroundMusic(const std::string & fileName, bool repeatMusic) {
  
  std::string folder { "assets/resources/music" };
  std::string fullPath {folder + fileName}; 

  if(musics.find(fullPath) != musics.end()) {
    return *musics[fullPath]; 
  }

  musics[fullPath] = std::make_unique<sf::Music>();

  if(!musics[fullPath]->openFromFile(fullPath)) {
    throw std::invalid_argument("music could not be loaded/found");
  }

  musics[fullPath]->play();

  if(repeatMusic) {
    musics[fullPath]->setLoop(true);
  }

  return *musics[fullPath];
}

sf::Image AssetsManager::loadCollisions(const std::string & fileName) {
        
  sf::Image image; 
        
    if (!image.loadFromFile(fileName)) {
        throw std::runtime_error("Error loading image: " + fileName);
    }
      return image; 
    }
