#define NPC_PLAYER_HPP

#ifndef PLAYER_HPP
#include <Player.hpp>
#endif


class NpcPlayer : Player{

NpcPlayer(const std::string & file); 

private:

sf::Texture texturePlayer; 
sf::Sprite spritePlayer; 
sf::Vector2f playerPosition;

};