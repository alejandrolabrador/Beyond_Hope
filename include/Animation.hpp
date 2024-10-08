#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

class Animation {

    public:
    
    std::vector<sf::Sprite> playerStates(unsigned int movements);

    private:

    AssetsManager assets;  
    sf::Sprite spritePlayer;
    sf::Texture texturePlayer; 
    static std::map<unsigned int, std::vector<sf::Sprite>> spriteCache;
};

#endif  // ANIMATION_HPP