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
#include <View.hpp>
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

Game(sf::RenderWindow& window);
Game(); 

void start(sf::RenderWindow & option); 


private: 

   Menu menu; 
   sf::RenderWindow window;
   Maps maps; 
   View view; 
   AssetsManager asset; 
};
