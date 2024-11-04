#include <Game.hpp>

Game::Game(sf::RenderWindow& window) : 
menu(window, Menu::Option::Play) {

menu; 
start(window);
}


void Game::start(sf::RenderWindow & screen){

auto && musicGame {asset.playBackgroundMusic("/BeyondHopeMusic.wav", true)};
std::unique_ptr<Player> player = std::make_unique<Player>("/antonio/Frontal/character_frontal.png");  
std::unique_ptr<NpcPlayer> npcPlayer = std::make_unique<NpcPlayer>("/carolina/character_frontal.png"); 
std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>("/inventory/life/3livesFull.png");
std::unique_ptr<Maps> map = std::make_unique<Maps>("/doors/blueDoor.png");
sf::View originalView = screen.getView();
mapTree = map->setMaps();
sf::Texture currentMap = mapTree[currentLevel];
spriteMap.setTexture(currentMap);

sf::Clock clock; 

while (screen.isOpen()) {
    
    sf::Event event;
    
    while (screen.pollEvent(event)) {

        if (event.type == sf::Event::KeyPressed) {


            if (event.key.code == sf::Keyboard::Escape) {
                musicGame.pause();
                screen.setView(originalView); 
                Menu menuContinue(screen, Menu::Option::Continue);
                musicGame.play(); 

            } 
            if(event.key.code == sf::Keyboard::Enter){
                map->updateDoor(player->getPosition()); 
            }
            if(event.key.code == sf::Keyboard::K){
                
                auto nextLevel = map->updateLevel(currentLevel, player->getPosition()); 
                currentMap = mapTree[nextLevel];
                spriteMap.setTexture(currentMap);
            }
            
            else {
                player->handleInput(event, &screen);
                
            }
        }
        
    }
    viewMap.viewCharacter(player, &spriteMap, screen.getSize());
    inventory->updateInventoryView(viewMap.getView().getCenter(), window.getSize()); 
    float deltaTime = clock.restart().asSeconds();    
    player->update(deltaTime);
    
    screen.setView(viewMap.getView()); 
    screen.clear();
    screen.draw(spriteMap);
    //screen.draw(*sprite);
    screen.draw(*map);
    screen.draw(*npcPlayer); 
    screen.draw(*player);
    screen.draw(*inventory);
    
    screen.display();
    
}}

  