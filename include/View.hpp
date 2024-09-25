#define VIEW_HPP

#include <AssetsManager.hpp>

//Throughout this class we will set target wiew for our main character.
class View: sf::View{

public:
 
void viewCharacter(sf::Sprite * player, sf::Sprite * map);
void updateViewBounds(sf::Sprite * map); 

private:

sf::View view; 
};