#define GAME_HPP

# ifndef PLAYER_HPP
# include <Player.hpp>
# endif

# ifndef MENU_HPP
# include <Menu.hpp>
# endif

# ifndef ASSETS_MANAGER_HPP
# include <AssetsManager.hpp>
# endif

#ifndef VIEW_HPP
#include <ViewMap.hpp>
#endif

#ifndef MAPS_HPP
#include <Maps.hpp>
#endif

#ifndef ANIMATION_HPP
#include <Animation.hpp>
#endif

#ifndef NPC_PLAYER_HPP
#include <NpcPlayer.hpp>
#endif

#ifndef INVENTORY_HPP
#include <Inventory.hpp>
#endif

class Game{

public: 

using mapRankedTreap = Designar::RankedTreap<std::pair<sf::Texture *, unsigned int>, std::less<std::pair<sf::Texture *, unsigned int>>> ; 

Game(sf::RenderWindow& window);
Game(); 

void start(sf::RenderWindow & option); 


private: 

   Menu menu; 
   sf::RenderWindow window;
   ViewMap viewMap; 
   AssetsManager asset; 
   mapRankedTreap mapTree; 
   
};
