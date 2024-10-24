#include <Player.hpp>

Player::Player(const std::string & file) : velocityPlayer(5.0f), jumpVelocity(10.0f), playerPosition(231, 493), isJumping(false), jumpFrame(0){

    currentPosition = 0;
    texturePlayer = assets.useTexture(file);
    spritePlayer.setTexture(texturePlayer); 
    spritePlayer.setScale(0.5f, 0.5f); 
    spritePlayer.setPosition(playerPosition);   
}

void Player::moveRight() {

    playerTextures = animation.playerStates(0);

    statesPlayer.clear();
 
    for (auto& texture : playerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.5f, 0.5f);
        statesPlayer.push_back(sprite);
    }

    int frame = currentPosition % statesPlayer.size();
    spritePlayer = statesPlayer[frame];
    playerPosition.x += velocityPlayer;
    spritePlayer.setPosition(playerPosition);
    currentPosition++; 
}

void Player::moveLeft() {
    
    playerTextures = animation.playerStates(1);
  
    statesPlayer.clear();
  
    for (auto& texture : playerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.5f, 0.5f);
        statesPlayer.push_back(sprite);
    }
  
    int frame = currentPosition % statesPlayer.size();
    spritePlayer = statesPlayer[frame];
    playerPosition.x -= velocityPlayer;
    spritePlayer.setPosition(playerPosition);
    currentPosition++; 
}

void Player::jump() {
    if (!isJumping) { 
        currentPosition = 0; 
        jumpFrame = 0;
        playerTextures = animation.playerStates(2); 
        statesPlayer.clear();

        for (auto& texture : playerTextures) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setScale(0.5f, 0.5f);
            statesPlayer.push_back(sprite);
        }      
        jumpVelocity = -100.0f; 
        isJumping = true; 
    }

}

void Player::update(float deltaTime) {
    
    playerPosition.y += jumpVelocity * deltaTime;
    jumpVelocity += 100.0f * deltaTime; 
   
    if (playerPosition.y >= 493) { 
        playerPosition.y = 493; 
        jumpVelocity = 0; 
        isJumping = false; 
        jumpFrame = 0; 
    } else {
        
        jumpFrame++;
        if (jumpFrame >= statesPlayer.size()) {
            jumpFrame = statesPlayer.size() - 1; 
        }
    }
    
    if (isJumping) {
        spritePlayer = statesPlayer[jumpFrame % statesPlayer.size()]; 
    } 
   
    updateSpritePosition();
}

void Player::handleInput(const sf::Event &event, sf::RenderWindow * screen) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::D:
                moveRight();
                break;
            case sf::Keyboard::A:
                moveLeft();
                break;
            case sf::Keyboard::Space:
                jump();
                break;
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!isJumping) {
            jump(); 
        }
        moveRight(); 
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!isJumping) {
            jump(); 
        }
        moveLeft(); 
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(spritePlayer, states);
    
}

sf::Vector2f Player::getPosition(){

    return playerPosition; 
}

void Player::updateSpritePosition(){
    
    spritePlayer.setPosition(playerPosition);
}