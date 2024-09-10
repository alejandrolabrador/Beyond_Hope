#define ASSETS_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetsManager{

public:

sf::Texture useTexture(const std::string, bool = false); 
sf::Music playBackgroundMusic(const std::string, bool = false);
sf::Sound especificSound(const std::string, bool = false);  

private:




};