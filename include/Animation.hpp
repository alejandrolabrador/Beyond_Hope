#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

class Animation {

    public:
    
    //Animation(); 
    //Animation(const std::string & file);

    std::vector<sf::Sprite> playerStates(unsigned int movements, sf::RenderWindow * screen);
    //virtual void draw(sf::RenderTarget&, sf::RenderStates) const; 

    private:

    AssetsManager assets; 
    std::vector<sf::Sprite> sprites;
    sf::Sprite spritePlayer;
    sf::Texture texturePlayer; 
    std::map<unsigned int, std::vector<sf::Sprite>> spriteCache; 
};

#endif  // ANIMATION_HPP