#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif



class Animation {

    public:
    
    std::vector<sf::Texture> doorStates(unsigned int color);
    std::vector<sf::Texture> inventoryStates(unsigned int quantity); 
    std::vector<sf::Texture> playerStates(unsigned int movement); 
    std::vector<sf::Texture> npcStates(unsigned int movement);
    std::vector<sf::Image> collisionStates(); 
    
    private:

    AssetsManager assets;  
    sf::Sprite spritePlayer;
    sf::Texture texturePlayer; 
    sf::Sprite spriteNpcPlayer; 
    sf::Texture textureNpcPlayer; 
    std::vector<std::string> sortFrames(std::string path);
    static std::map<unsigned int, std::vector<sf::Texture>> textureCache; 
    static std::map<unsigned int, std::vector<sf::Texture>> textureNpcCache; 
    static std::map<unsigned int, std::vector<sf::Texture>> textureInventoryCache; 
    static std::map<unsigned int, std::vector<sf::Texture>> textureDoorCache;

};  

#endif  // ANIMATION_HPP