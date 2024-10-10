#define NPC_PLAYER_HPP

#ifndef PLAYER_HPP
#include <Player.hpp>
#endif


class NpcPlayer: public Player{

public: 

NpcPlayer(const std::string & file); 

private:

sf::Vector2f playerPosition;
void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};