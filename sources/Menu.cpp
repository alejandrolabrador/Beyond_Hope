#include <Menu.hpp>



Menu::Menu(sf::RenderWindow & menuScreen){

AssetsManager asset; 

auto texture {asset.useTexture("/menu/menuPlay.png")};

sf::Sprite sprite; 
sprite.setTexture(texture); 

sf::Vector2u imageSize = texture.getSize(); 

sf::Vector2u windowSize = menuScreen.getSize();

float scaleX = (float)windowSize.x / imageSize.x;
float scaleY = (float)windowSize.y / imageSize.y;

sprite.setScale(scaleX, scaleY);

while (menuScreen.isOpen()) {
    sf::Event event;
    while (menuScreen.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            menuScreen.close();
    }

    menuScreen.clear();
    menuScreen.draw(sprite);
    menuScreen.display();

    while(true){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
        
    auto state {Option::Continue}; 
    auto mapTexture {map.useTexture("/maps/actualBeachMap.png")}; 


    }
}
}

}



void Menu::startGame(){
 
    AssetsManager menu; 
    sf::Texture texture;  

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){

    switch(state){

    case Option::Continue:
    texture = menu.useTexture("/menu/MenuContinue");
    break; 
    case Option::Quit:
    break; 


    }}
}