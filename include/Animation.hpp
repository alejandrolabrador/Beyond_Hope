#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

class Animation {

    public:
    
    std::vector<sf::Sprite> playerSprites(unsigned int movements);

    std::vector<sf::Texture> inventoryStates(unsigned int quantity); 
    std::vector<sf::Texture> playerStates(unsigned int movement); 

    private:

    AssetsManager assets;  
    sf::Sprite spritePlayer;
    sf::Texture texturePlayer; 
    static std::map<unsigned int, std::vector<sf::Texture>> textureCache; 
    static std::map<unsigned int, std::vector<sf::Sprite>> spriteCache;
    static std::map<unsigned int, std::vector<sf::Texture>> textureInventoryCache; 

};  

#endif  // ANIMATION_HPP