#include <Game.hpp>

void Game::start(){

    //while(){}

      
    AssetsManager assetsManager;

    sf::Texture& texture = assetsManager.useTexture("menu/menu.png");
    sf::Sprite sprite(texture);    
    sf::VideoMode vm = sf::VideoMode::getDesktopMode();
    sf::View view;
    view.setSize(vm.width, vm.height);

    float scaleX = vm.width / texture.getSize().x;
    float scaleY = vm.height / texture.getSize().y;

    float scale = std::min(scaleX, scaleY);
    sprite.setScale(scale, scale);

    sprite.setPosition(vm.width / 2, vm.height / 2);

    sf::RenderWindow window(vm, "Image Display");
    window.setView(view);

    sf::Clock clock; 


    //This is just testing the view.
    while (window.isOpen() && clock.getElapsedTime().asSeconds() < 10) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();}
    }

        // Clear the window
        //window.clear();

    window.draw(sprite);

    window.display();

    }
}
  