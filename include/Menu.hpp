#define MENU_HPP

# ifndef ASSETS_MANAGER_HPP
# include <AssetsManager.hpp>
# endif

#include <SFML/Window.hpp>

class Menu{

public:


Menu(sf::RenderWindow & screenMenu); 

enum class Option{ 
    Play, 
    Quit,
    Continue,
    QuitContinue,
    };
  
Option state = Option::Play; 

Option startGame(sf::RenderWindow & window); 

Option getSelectedOption() { return state; }

private:

AssetsManager map; 
sf::Sprite spritePlay;
sf::Sprite spriteQuit;  
sf::Sprite spriteQuitContinue;
sf::Sprite spriteContinue; 


};