#include <Game.hpp>


Game::Game(sf::RenderWindow& window) : menu(window, Menu::Option::Play) {

menu; 
start(window);
}


void Game::start(sf::RenderWindow & screen){

AssetsManager asset;
sf::Texture textureMap {asset.useTexture("/maps/firstMap.png")};
sf::Texture texturePlayer {asset.useTexture("/antonio/Frontal/character_frontal.png")}; 

sf::Sprite spriteMap;
sf::Sprite spritePlayer; 

spriteMap.setTexture(textureMap);
spritePlayer.setTexture(texturePlayer); 

while(screen.isOpen()){
    sf::Event event; 

    while(screen.pollEvent(event)){

        view.viewCharacter(&spritePlayer, &spriteMap);
    }

    screen.clear();
    screen.draw(spriteMap);
    screen.draw(spritePlayer); 
    screen.display();

    if(event.key.code ==  sf::Keyboard::Escape){

        Menu menucito(screen, Menu::Option::Continue); 
}


}}

  