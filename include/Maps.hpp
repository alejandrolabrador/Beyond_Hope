#define MAPS_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

#ifndef VIEW_HPP
#include <View.hpp>
#endif

class Maps{

    void insertMap(sf::Texture * map, unsigned int priority); 
    

    private:

    Designar::RankedTreap<std::pair<sf::Texture*, unsigned int>, std::less<std::pair<sf::Texture*, unsigned int>>> mapTree;

};