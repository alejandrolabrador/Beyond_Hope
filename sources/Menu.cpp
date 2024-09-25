#include <Menu.hpp>


Menu::Menu(sf::RenderWindow & menuScreen, Option mood){

    AssetsManager asset; 
    sf::Texture texturePlay {asset.useTexture("/menu/menuPlay.png")};
    sf::Texture textureQuit {asset.useTexture("/menu/MenuExit.png")}; 
    sf::Texture textureQuitContinue {asset.useTexture("/menu/MenuExitContinue.png")};
    sf::Texture textureContinue {asset.useTexture("/menu/MenuContinue.png")};

    spriteQuit.setTexture(textureQuit);
    spritePlay.setTexture(texturePlay); 
    spriteQuitContinue.setTexture(textureQuitContinue);
    spriteContinue.setTexture(textureContinue);

    sf::Vector2u imageSize = texturePlay.getSize(); 
    sf::Vector2u windowSize = menuScreen.getSize();

    float scaleX = (float)windowSize.x / imageSize.x;
    float scaleY = (float)windowSize.y / imageSize.y;

    spritePlay.setScale(scaleX, scaleY);
    spriteQuit.setScale(scaleX, scaleY);
    spriteQuitContinue.setScale(scaleX, scaleY); 
    spriteContinue.setScale(scaleX, scaleY); 

    startGame(menuScreen, mood); 
      
}


Menu::Option Menu::startGame(sf::RenderWindow & window, Menu::Option moodScreen){

    bool closeWindow = false;
    state = moodScreen; 

    while (window.isOpen() && !closeWindow) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    closeWindow = true; 
                }
                if (event.key.code == sf::Keyboard::Down && state== Option::Play) {
                    state = Option::Quit; 
                }
                if (event.key.code == sf::Keyboard::Up && state == Option::Quit) {

                    state = Option::Play; 
                }
                if(event.key.code == sf::Keyboard::Up && state == Option::QuitContinue){

                    state = Option::Continue; 
                }
                if(event.key.code == sf::Keyboard::Down && state == Option::Continue){
                    state = Option::QuitContinue; 
                }
                if (event.key.code == sf::Keyboard::Enter && state == Option::Quit) {
                    closeWindow = true; 
                }
                if (event.key.code == sf::Keyboard::Enter && state == Option::QuitContinue) {
                    closeWindow = true; 
                }
                if(event.key.code == sf::Keyboard::Enter && state == Option::Play){
                    
                    return Option::Play; 
                }
                if(event.key.code == sf::Keyboard::Enter && state == Option::Continue){
                    
                    return Option::Continue; 
                }
            }
        }
        window.clear(); 
        
        switch (state) {
            case Option::Play: 
                window.draw(spritePlay);
                break;  

            case Option::Quit:
                window.draw(spriteQuit); 
                break;  

            case Option::QuitContinue:
                window.draw(spriteQuitContinue);
                break;

            case Option::Continue:
                window.draw(spriteContinue); 
                break; 
        }

        window.display();

        if (closeWindow) {
            window.close(); 
        }
    }
}
