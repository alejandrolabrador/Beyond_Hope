#include <Menu.hpp>


Menu::Menu(sf::RenderWindow & menuScreen) : menuScreen_(menuScreen){

    AssetsManager asset; 
    sf::Texture texturePlay {asset.useTexture("/menu/menuPlay.png")};
    sf::Texture textureQuit {asset.useTexture("/menu/MenuExit.png")}; 
    sf::Texture textureQuitContinue {asset.useTexture("/menu/MenuContinue.png")};
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


    bool closeWindow = false;
    state = Option::Play;

    while (menuScreen_.isOpen() && !closeWindow) {
        sf::Event event;
        while (menuScreen_.pollEvent(event)) {
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    closeWindow = true; 
                }
                if (event.key.code == sf::Keyboard::Down) {
                    state = Option::Quit; 
                }
                if (event.key.code == sf::Keyboard::Up) {
                    state = Option::Play; 
                }
                if (event.key.code == sf::Keyboard::Enter && state == Option::Quit) {
                    closeWindow = true; 
                }
                if(event.key.code == sf::Keyboard::Enter && state == Option::Play){
                    //Implementation to what we expect 4 the game to show.
                }
            }
        }
        menuScreen_.clear(); 

        switch (state) {
            case Option::Play: 
                menuScreen_.draw(spritePlay);
                break;  

            case Option::Quit:
                menuScreen_.draw(spriteQuit); 
                break;  

            case Option::QuitContinue:
                menuScreen_.draw(spriteQuitContinue);
                break;

            case Option::Continue:
                menuScreen_.draw(spriteContinue); 
                break; 
        }

        menuScreen_.display();

        if (closeWindow) {
            menuScreen_.close(); 
        }
    }
      
}


void Menu::startGame(){

   /*bool closeWindow = false;
   state = Option::Play;

    while (menuScreen_.isOpen() && !closeWindow) {
        sf::Event event;
        while (menuScreen_.pollEvent(event)) {
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    closeWindow = true; 
                }
                if (event.key.code == sf::Keyboard::Down) {
                    state = Option::Quit; 
                }
                if (event.key.code == sf::Keyboard::Up) {
                    state = Option::Play; 
                }
                if (event.key.code == sf::Keyboard::Enter && state == Option::Quit) {
                    closeWindow = true; 
                }
            }
        }
        menuScreen_.clear(); 

        switch (state) {
            case Option::Play: 
                menuScreen_.draw(spritePlay);
                break;  

            case Option::Quit:
                menuScreen_.draw(spriteQuit); 
                break;  

            case Option::QuitContinue:
                menuScreen_.draw(spriteQuitContinue);
                break;

            case Option::Continue:
                menuScreen_.draw(spriteContinue); 
                break; 
        }

        menuScreen_.display();

        if (closeWindow) {
            menuScreen_.close(); 
        }
    }
*/
}
