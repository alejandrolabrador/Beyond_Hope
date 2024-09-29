#include <Maps.hpp>

void Maps::insertMap (sf::Texture * map, unsigned int priority){

    std::pair<sf::Texture*, unsigned int> pair(map, priority);
    mapTree.insert(pair);
}