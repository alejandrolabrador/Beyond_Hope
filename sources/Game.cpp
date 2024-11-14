#include <Game.hpp>

Game::Game(sf::RenderWindow& window) : 
menu(window, Menu::Option::Play) {

gameOver = asset.useTexture("/resources/fonts/gameOver.png");
spriteGameOver.setTexture(gameOver);
spriteGameOver.setScale(1.8f, 1.8f);

menu; 
start(window);
}


void Game::start(sf::RenderWindow & screen){

auto && musicGame {asset.playBackgroundMusic("/BeyondHopeMusic.wav", true)};
std::unique_ptr<Player> player = std::make_unique<Player>("/antonio/Frontal/character_frontal.png");  
std::unique_ptr<NpcPlayer> npcPlayer = std::make_unique<NpcPlayer>("/carolina/Frontal/character_frontal.png"); 
std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>("/inventory/life/3livesFull.png");
std::unique_ptr<Maps> map = std::make_unique<Maps>("/doors/blueDoor.png");
imageCollisions = animation.collisionStates(); 
std::unique_ptr<Collisions> collisions = std::make_unique<Collisions>(imageCollisions[0]);
sf::View originalView = screen.getView();
sf::Color targetColor(255, 0, 0);
mapTree = map->setMaps();
sf::Texture currentMap = mapTree[currentLevel];
spriteMap.setTexture(currentMap);

sf::Clock clock; 

while (screen.isOpen()) {
    
    sf::Event event;
    
    while (screen.pollEvent(event)) {

        if (event.type == sf::Event::KeyPressed) {


            if (event.key.code == sf::Keyboard::Escape) {
                
                if(game == gameState::over){
                   screen.close(); }

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
                
                if(nextLevel != 0){
                    npcPlayer->NpcPlayerPosition = npcPlayer->setOriginalPosition(); 
                    player->playerPosition = player->setOriginalPosition(); 
                     
                }
                currentLevel+= nextLevel; 
                currentMap = mapTree[currentLevel];
                spriteMap.setTexture(currentMap);
            }
            
            else {

                if(game == gameState::play){
                player->handleInput(event, &screen);
                npcPlayer->handleInput(event, &screen);}
                
            }
        }
        
    }
    viewMap.viewCharacter(player, &spriteMap, screen.getSize());
    inventory->updateInventoryView(viewMap.getView().getCenter(), originalView.getCenter()); 
    
    float deltaTime = clock.restart().asSeconds();    
    player->update(deltaTime);
    npcPlayer->update(deltaTime);

    if(collisions->crackCollision(player, imageCollisions[currentLevel], targetColor)){
        
        sf::Vector2f newPosition((player->playerPosition.x-100), 493);
        items = Inventory::items::medicine; 
        inventory->removeItem(items, 1);
        inventory->updateSprite(items);
        player->playerPosition = newPosition; 
        
      if(inventory->getItemQuantity(items) == 0){
    
        game = gameState::over; 
    }  
    }
    
    screen.setView(viewMap.getView()); 
    screen.clear();
    
    screen.draw(spriteMap);
    if (currentLevel < 3) {
    screen.draw(*map);} 
    screen.draw(*npcPlayer); 
    screen.draw(*player);
    screen.draw(*inventory);
    if(game == gameState::over){
    spriteGameOver.setPosition(viewMap.getView().getCenter().x /2 ,viewMap.getView().getCenter().y / 2); 
    screen.draw(spriteGameOver);
    musicGame.pause();}
    screen.display();
    
}}

  