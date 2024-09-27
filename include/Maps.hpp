#define MAPS_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

#ifndef VIEW_HPP
#include <View.hpp>
#endif

class Maps{

    void insertMap(sf::Texture map, int priority); 
    

    private:

    Designar::RankedTreap<sf::Texture> mapTree; 


};