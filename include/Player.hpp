#define PLAYER_HPP

#include <vector>

# ifndef ASSETS_MANAGER_HPP
# include <AssetsManager.hpp>
# endif


class Player{

public:

void updateStatus();
bool dead();  


private:

unsigned int health; 
std::vector<sf::Texture> states;  

};