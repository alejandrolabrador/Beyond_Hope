#include <Game.hpp>


Game::Game(sf::RenderWindow& window) : menu(window) {

menu.startGame(); 
start(); 

}


void Game::start(){

while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){


}
}
  