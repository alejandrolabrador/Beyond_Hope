#define ASSETS_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetsManager{

public:

//~AssetsManager(); 

sf::Texture & useTexture(const std::string &); 
sf::Music & playBackgroundMusic(const std::string &);
sf::Sound & especificSound(const std::string &);  

private:

std::map<std::string, sf::Texture> textures; 


};