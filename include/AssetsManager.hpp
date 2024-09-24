#ifndef ASSETS_MANAGER_HPP
#define ASSETS_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdexcept>
#include <list.hpp>
#include <array.hpp>
#include <set.hpp>


class AssetsManager{

public:

//~AssetsManager(); 

sf::Texture & useTexture(const std::string &); 
sf::Music & playBackgroundMusic(const std::string &);
sf::Sound & especificSound(const std::string &);  

private:

std::map<std::string, sf::Texture> textures; 

};

#endif  // ASSETS_MANAGER_HPP