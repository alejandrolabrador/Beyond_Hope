#define MENU_HPP

# ifndef ASSETS_MANAGER_HPP
# include <AssetsManager.hpp>
# endif

#include <SFML/Window.hpp>

#ifndef VIEW_HPP
#include <View.hpp>
#endif

class Menu{

public:


enum class Option{ 
    Play, 
    Quit,
    Continue,
    QuitContinue,
    };
    
Menu(sf::RenderWindow & screenMenu, Option screenMode); 
  
Option state = Option::Play; 

Option startGame(sf::RenderWindow & window, Option mood); 


private:

AssetsManager map; 
sf::Sprite spritePlay;
sf::Sprite spriteQuit;  
sf::Sprite spriteQuitContinue;
sf::Sprite spriteContinue; 


};