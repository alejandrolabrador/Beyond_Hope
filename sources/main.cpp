
#include <Game.hpp>


int main(int argc, char * argv[])
{
	sf::VideoMode screen = sf::VideoMode::getFullscreenModes()[0]; 
	sf::RenderWindow screenGame(screen, "Beyond Hope", sf::Style::Fullscreen);
	Game game(screenGame);
	return 0;
}
