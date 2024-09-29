#define PLAYER_HPP


# ifndef ASSETS_MANAGER_HPP
# include <AssetsManager.hpp>
# endif


class Player{

public:


sf::Sprite & setPlayer(const std::string & file); 
void updateStatus();
bool dead();  


private:

unsigned int health; 
std::vector<sf::Texture *> states;  
AssetsManager assets; 
sf::Sprite spritePlayer;
sf::Texture texturePlayer; 

};