#include <NpcPlayer.hpp>

NpcPlayer::NpcPlayer(const std::string &file) 
    : Player(file), playerPosition(40, 493), velocityPlayer(5.0f), jumpVelocity(0.0f), isJumping(false), jumpFrame(0), currentPosition(0) {

    texturePlayer = assets.useTexture(file);
    spritePlayer.setTexture(texturePlayer); 
    spritePlayer.setScale(0.21f, 0.21f); 
    spritePlayer.setPosition(playerPosition);  
}

void NpcPlayer::moveRight() {
    playerTextures = animation.playerStates(0); 
    statesPlayer.clear();

    for (auto& texture : playerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.21f, 0.21f);
        statesPlayer.push_back(sprite);
    }

    int frame = currentPosition % statesPlayer.size();
    spritePlayer = statesPlayer[frame];
    playerPosition.x += velocityPlayer;
    spritePlayer.setPosition(playerPosition);
    currentPosition++; 
}

void NpcPlayer::moveLeft() {
    playerTextures = animation.playerStates(1); 
    statesPlayer.clear();

    for (auto& texture : playerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.21f, 0.21f);
        statesPlayer.push_back(sprite);
    }

    int frame = currentPosition % statesPlayer.size();
    spritePlayer = statesPlayer[frame];
    playerPosition.x -= velocityPlayer;
    spritePlayer.setPosition(playerPosition);
    currentPosition++; 
}

void NpcPlayer::jump() {
    currentPosition = 0; 
    jumpFrame = 0;
    playerTextures = animation.playerStates(2); 
    std::cout << "Jump textures count: " << playerTextures.size() << std::endl; 
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

void NpcPlayer::update(float deltaTime) {
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

void NpcPlayer::handleInput(const sf::Event &event, sf::RenderWindow *screen) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Right:
                moveRight();
                break;
            case sf::Keyboard::Left:
                moveLeft();
                break;
            case sf::Keyboard::Up:
                jump();
                break;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (!isJumping) {
            jump(); 
        }
        moveRight(); 
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (!isJumping) {
            jump(); 
        }
        moveLeft(); 
    }
}

void NpcPlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(spritePlayer, states);
}

void NpcPlayer::updateSpritePosition() {
    spritePlayer.setPosition(playerPosition);
}