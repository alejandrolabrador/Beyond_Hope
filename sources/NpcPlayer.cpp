#include <NpcPlayer.hpp>

NpcPlayer::NpcPlayer(const std::string &file) 
    : Player(file), NpcPlayerPosition(40, 493), velocityNpcPlayer(5.0f), jumpVelocity(0.0f), isJumping(false), jumpFrame(0), currentPosition(0) {

    textureNpcPlayer = assets.useTexture(file);
    spriteNpcPlayer.setTexture(texturePlayer); 
    spriteNpcPlayer.setScale(0.21f, 0.21f); 
    spriteNpcPlayer.setPosition(NpcPlayerPosition);  
}

void NpcPlayer::moveRight() {
    NpcPlayerTextures = animation.NpcStates(0); 
    statesNpcPlayer.clear();

    for (auto& texture : NpcPlayerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.21f, 0.21f);
        statesNpcPlayer.push_back(sprite);
    }

    int frame = currentPosition % statesNpcPlayer.size();
    spriteNpcPlayer = statesNpcPlayer[frame];
    NpcPlayerPosition.x += velocityNpcPlayer;
    spriteNpcPlayer.setPosition(NpcPlayerPosition);
    currentPosition++; 
}

void NpcPlayer::moveLeft() {
    playerTextures = animation.NpcStates(1); 
    statesPlayer.clear();

    for (auto& texture : NpcPlayerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.21f, 0.21f);
        statesNpcPlayer.push_back(sprite);
    }

    int frame = currentPosition % statesNpcPlayer.size();
    spriteNpcPlayer = statesNpcPlayer[frame];
    NpcPlayerPosition.x -= velocityNpcPlayer;
    spriteNpcPlayer.setPosition(NpcPlayerPosition);
    currentPosition++; 
}

void NpcPlayer::jump() {
    currentPosition = 0; 
    jumpFrame = 0;
    NpcPlayerTextures = animation.NpcStates(2); 
    statesPlayer.clear();

    for (auto& texture : NpcPlayerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.21f, 0.21f);
        statesNpcPlayer.push_back(sprite);
    }      
    jumpVelocity = -100.0f; 
    isJumping = true; 
}

void NpcPlayer::jumpRight() {
    
    currentPosition = 0; 
    jumpFrame = 0;
    NpcPlayerTextures = animation.NpcStates(2); 
    statesNpcPlayer.clear();

    for (auto& texture : NpcPlayerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.21f, 0.21f);
        statesNpcPlayer.push_back(sprite);
    }      
    jumpVelocity = -100.0f; 
    NpcPlayerPosition.x += velocityNpcPlayer; 
    isJumping = true; 
}

void NpcPlayer::jumpLeft() {
    
    currentPosition = 0; 
    jumpFrame = 0;
    NpcPlayerTextures = animation.NpcStates(3); 
    statesNpcPlayer.clear();

    for (auto& texture : NpcPlayerTextures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(0.21f, 0.21f);
        statesPlayer.push_back(sprite);
    }      
    jumpVelocity = -100.0f; 
    NpcPlayerPosition.x -= velocityNpcPlayer; 
    isJumping = true; 
}

void NpcPlayer::update(float deltaTime) {
    NpcPlayerPosition.y += jumpVelocity * deltaTime;
    jumpVelocity += 100.0f * deltaTime; 

    if (NpcPlayerPosition.y >= 493) { 
        NpcPlayerPosition.y = 493; 
        jumpVelocity = 0; 
        isJumping = false; 
        jumpFrame = 0; 
    } else {
        jumpFrame++;
        if (jumpFrame >= statesNpcPlayer.size()) {
            jumpFrame = statesNpcPlayer.size() - 1; 
        }
    }
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
    target.draw(spriteNpcPlayer, states);
}

void NpcPlayer::updateSpritePosition() {
    spriteNpcPlayer.setPosition(NpcPlayerPosition);
}