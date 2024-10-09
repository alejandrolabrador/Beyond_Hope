#include <Player.hpp>

Player::Player(const std::string & file) : velocityPlayer(5.0f), jumpVelocity(10.0f), playerPosition(231, 479), isJumping(false){

    currentPosition = 0;
    texturePlayer = assets.useTexture(file);
    spritePlayer.setTexture(texturePlayer); 
    spritePlayer.setScale(0.5f, 0.5f); 
    spritePlayer.setPosition(playerPosition);   

}

void Player::moveRight() {

    playerTextures = animation.playerStates(0);

    for(auto player : playerTextures){

    spritePlayer.setTexture(playerTextures[currentPosition]);
    currentPosition++; 
    currentPosition%=(int)playerTextures.size();
    playerPosition.x += velocityPlayer;
    spritePlayer.setPosition(playerPosition);
    }
}

void Player::moveLeft() {
    
    playerTextures = animation.playerStates(1);

    for(auto player : playerTextures){

    spritePlayer.setTexture(playerTextures[currentPosition]);
    currentPosition++; 
    currentPosition%=(int)playerTextures.size();
    playerPosition.x -= velocityPlayer;
    spritePlayer.setPosition(playerPosition);}
}

void Player::jump() {
    if (!isJumping) {
        playerTextures = animation.playerStates(2);
        jumpVelocity = -10.0f;
        isJumping = true;
    }
   
}

void Player::update(float deltaTime) {
    playerPosition.x += velocityPlayer * deltaTime;
    playerPosition.y += jumpVelocity * deltaTime;

    jumpVelocity += 0.5f * deltaTime;
    if (playerPosition.y > 0) {
        playerPosition.y = 0;
        jumpVelocity = 0;
        isJumping = false;
    }

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
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(spritePlayer, states);
    
}