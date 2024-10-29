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

class Maps : sf::Drawable{

    void getMap(); 
    
    private:

    bool doorOpen; 
    AssetsManager assets; 
    unsigned int priority = 0; 
    Designar::RankedTreap<std::pair<sf::Texture*, unsigned int>, std::less<std::pair<sf::Texture*, unsigned int>>> mapTree;
    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override; 
};