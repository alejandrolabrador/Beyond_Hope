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

class Game {

public: 

Game(sf::RenderWindow& window);
Game(); 

void start(); 

private: 

   Menu menu; 
   sf::RenderWindow window; 

};
