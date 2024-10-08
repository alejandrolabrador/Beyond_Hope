#include <Game.hpp>

Game::Game(sf::RenderWindow& window) : 
menu(window, Menu::Option::Play) {

menu; 
start(window);
}


void Game::start(sf::RenderWindow & screen){

sf::Sprite spriteMap;
sf::Sprite spritePlayer; 
auto && musicGame {asset.playBackgroundMusic("/BeyondHopeMusic.wav", true)};

sf::Texture textureMap {asset.useTexture("/maps/firstMap.png")};
spriteMap.setTexture(textureMap);

while (screen.isOpen()) {

    std::unique_ptr<Player> player = std::make_unique<Player>("/antonio/Frontal/character_frontal.png");  
    sf::Event event;
    
    while (screen.pollEvent(event)) {

        if (event.type == sf::Event::KeyPressed) {


            if (event.key.code == sf::Keyboard::Escape) {
                musicGame.stop();
                Menu menuContinue(screen, Menu::Option::Continue);

            } else {
                player->handleInput(event, &screen);
            }
        }
        view.viewCharacter(&spritePlayer, &spriteMap);
    }

    screen.clear();
    screen.draw(spriteMap);
    screen.draw(*player);
    screen.display();
}}

  