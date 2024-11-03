#define VIEW_HPP

#include <AssetsManager.hpp>

#ifndef PLAYER_HPP
#include <Player.hpp>
#endif

#ifndef INVENTORY_HPP
#include <Inventory.hpp>
#endif

//Throughout this class we will set target wiew for our main character.
class ViewMap: sf::View{

public:
 
void viewCharacter(std::unique_ptr<Player>& target, sf::Sprite * map, sf::Vector2u sizes);
void updateViewBounds(sf::Sprite * map, sf::Vector2u mapSize); 
sf::View getView() const; 

private:

//Inventory inventory;
sf::View view;  

};