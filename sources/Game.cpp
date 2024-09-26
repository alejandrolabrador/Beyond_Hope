#include <Game.hpp>


Game::Game(sf::RenderWindow& window) : menu(window, Menu::Option::Play) {

menu; 
start(window);
}


void Game::start(sf::RenderWindow & screen){

AssetsManager asset;
sf::Sprite spriteMap;
sf::Sprite spritePlayer; 

sf::Texture textureMap {asset.useTexture("/maps/firstMap.png")};
spriteMap.setTexture(textureMap);

spritePlayer = player.setPlayer("/antonio/Frontal/character_frontal.png");

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

        Menu menuContinue(screen, Menu::Option::Continue); 
    }


}}

  