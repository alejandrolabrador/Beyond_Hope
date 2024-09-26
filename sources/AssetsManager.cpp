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

sf::Music & AssetsManager::playBackgroundMusic(const std::string & fileName, bool repeatMusic){

std::string folder { "assets/resources/music"};
std::string fullPath {folder + fileName}; 

sf::Music music; 

if(musics.find(fullPath) != musics.end()) {

    return musics[fullPath]; 
}

if(!musics[fullPath].openFromFile(fullPath)) {
    throw std::invalid_argument("music could not be loaded/found");
}

musics[fullPath].play();

if(repeatMusic) {
    musics[fullPath].setLoop(true);
}

return musics[fullPath];


}