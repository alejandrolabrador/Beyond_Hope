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
    QuitContinue,
    };
  
Option state = Option::Play; 
AssetsManager map; 
sf::Sprite spritePlay;
sf::Sprite spriteQuit;  
sf::Sprite spriteQuitContinue;
sf::Sprite spriteContinue; 
sf::RenderWindow &menuScreen_; //Its used to change between pngs, while a key is pressed.

};