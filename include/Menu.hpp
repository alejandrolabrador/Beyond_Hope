#define MENU_HPP

# ifndef ASSET_MANAGER_HPP
# include <AssetsManager.hpp>
# endif

#include <SFML/Window.hpp>

class Menu{

public:

Menu(sf::RenderWindow & screenMenu); 

void startGame(); 

private:

enum class Option{ 
    Play, 
    Quit,
    Continue,
    };
  
Option state; 
AssetsManager map; 

};