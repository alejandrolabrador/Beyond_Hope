#include <Player.hpp>

Player::Player(const std::string & file) : velocityPlayer(5.0f), jumpVelocity(10.0f), playerPosition(100, 100), isJumping(false), currentPosition(0) {

    texturePlayer = assets.useTexture(file);
    spritePlayer.setTexture(texturePlayer); 
    spritePlayer.setScale(0.5f, 0.5f); 
    spritePlayer.setPosition(231, 485);  
    

}



void Player::moveRight(sf::RenderWindow * screen) {

    statesPlayer = animation.playerStates(0);
    spritePlayer = statesPlayer[currentPosition]; 
    currentPosition = (currentPosition + 1) % statesPlayer.size(); 
    playerPosition.x += velocityPlayer;
    spritePlayer.setPosition(playerPosition);
}

void Player::moveLeft(sf::RenderWindow * screen) {
    statesPlayer = animation.playerStates(1); 
    spritePlayer = statesPlayer[currentPosition]; 
    currentPosition = (currentPosition + 1) % statesPlayer.size(); 
    playerPosition.x -= velocityPlayer;
    spritePlayer.setPosition(playerPosition); 
   
}

void Player::jump(sf::RenderWindow * screen) {
    if (!isJumping) {
        statesPlayer = animation.playerStates(2); 
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
                moveRight(screen);
                break;
            case sf::Keyboard::A:
                moveLeft(screen);
                break;
            case sf::Keyboard::Space:
                jump(screen);
                break;
        }
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(spritePlayer, states);
    
}