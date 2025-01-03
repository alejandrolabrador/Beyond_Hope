#define MAPS_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

#ifndef VIEW_HPP
#include <ViewMap.hpp>
#endif

#ifndef ASSETSMANAGER_HPP
#include <AssetsManager.hpp>
#endif

#ifndef ANIMATION_HPP
#include <Animation.hpp>
#endif

class Maps : public sf::Drawable{

    public: 

    //using mapRankedTreap = Designar::RankedTreap<std::pair<sf::Texture *, unsigned int>, std::less<std::pair<sf::Texture *, unsigned int>>>;

    Maps(const std::string & file); 
    std::map<unsigned int, sf::Texture> setMaps(); 
    int updateLevel(unsigned int map, sf::Vector2f playerPosition); 
    void updateDoor(sf::Vector2f doorPosition);
    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override; 
    
    private:

    Animation animation; 
    std::vector<sf::Texture> blueDoorTextures;
    std::vector<sf::Texture> redDoorTextures; 
    bool redDoorOpen = false; 
    bool blueDoorOpen = false; 
    AssetsManager assets; 
    unsigned int priority = 0; 
    std::map<unsigned int, sf::Texture> mapTree;
    std::vector<sf::Texture> doorStates; 
    sf::Sprite spriteRedDoor;
    sf::Sprite spriteBlueDoor; 
    sf::Sprite doorRedOpen;
    sf::Sprite doorBlueOpen;  
    sf::Sprite spriteRedClosed;
    sf::Sprite spriteBlueClosed; 
    sf::Vector2f redPosition; 
    sf::Vector2f bluePosition; 
    sf::Texture textureBlueDoor; 
    sf::Texture textureRedDoor; 

};