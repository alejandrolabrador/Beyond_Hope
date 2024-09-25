#include <Game.hpp>


Game::Game(sf::RenderWindow& window) : menu(window) {

menu;  
state = menu.getSelectedOption();
start(state);
}


void Game::start(Menu::Option gameOption){

sf::VideoMode screen = sf::VideoMode::getFullscreenModes()[0]; 
	sf::RenderWindow window(screen, "Beyond Hope", sf::Style::Fullscreen);

    if(gameOption == Menu::Option::Play){

while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){

AssetsManager asset;
sf::Texture textureMap {asset.useTexture("/maps/firstMap.png")};
sf::Sprite spriteMap; 
spriteMap.setTexture(textureMap);

sf::Texture texturePlayer {asset.useTexture("/antonio/Frontal/character_frontal.png")}; 
sf::Sprite spritePlayer; 
spritePlayer.setTexture(texturePlayer);

View viewMap; // Create the View object once

if (!window.isOpen()) {
    std::cerr << "Failed to create window!" << std::endl;

}
while(window.isOpen()){
    sf::Event event; 

    while(window.pollEvent(event)){
        // Handle events here, e.g. update the player sprite position
        // ...

        viewMap.viewCharacter(&spritePlayer, &spriteMap);
    }

    window.clear();
    window.draw(spritePlayer); 
    window.draw(spriteMap);
    window.display();
}
}
}}

  