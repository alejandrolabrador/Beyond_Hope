#include <Game.hpp>


Game::Game(sf::RenderWindow& window) : menu(window) {

menu;  
state = menu.getSelectedOption();
start(state); 

}


void Game::start(Menu::Option gameOption){
 

    if(gameOption == Menu::Option::Play){

while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){

AssetsManager asset; 
sf::Texture textureMap {asset.useTexture("/maps/firstMap.png")};
sf::Sprite spriteMap; 
spriteMap.setTexture(textureMap);

sf::Texture texturePlayer {asset.useTexture("/antonio/Frontal/character_frontal.png")}; 
sf::Sprite spritePlayer; 
spritePlayer.setTexture(texturePlayer); 

View viewMap; 
viewMap.viewCharacter(&spritePlayer, &spriteMap);
}
}
}

  