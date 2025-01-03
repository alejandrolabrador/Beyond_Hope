#ifndef ASSETS_MANAGER_HPP
#define ASSETS_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdexcept>
#include <list.hpp>
#include <array.hpp>
#include <set.hpp>
#include <vector>
#include <filesystem>


class AssetsManager{

public:

//~AssetsManager(); 

sf::Texture & useTexture(const std::string &); 
sf::Music & playBackgroundMusic(const std::string &, bool repeatMusic);
sf::Sound & especificSound(const std::string &);  
sf::Image loadCollisions(const std::string &); 


private:

std::map<std::string, sf::Texture> textures; 
std::map<std::string, std::unique_ptr<sf::Music>> musics;
sf::Image image; 

};

#endif  // ASSETS_MANAGER_HPP