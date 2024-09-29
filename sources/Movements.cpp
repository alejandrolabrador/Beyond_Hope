#include <Movements.hpp>

Movements::Movements() : velocityPlayer(5.0f), jumpVelocity(10.0f), playerPosition(0, 0), isJumping(false) {}

void Movements::moveRight(sf::RenderWindow * position) {

    statesPlayer = animation.playerStates(0, position);
    playerPosition.x += velocityPlayer;
}

void Movements::moveLeft(sf::RenderWindow * position) {

    /*statesPlayer = animation.playerStates(1, position); 
    
    for (const auto& sprite: statesPlayer){
        position->draw(sprite); 
    }
    position->display();*/
    statesPlayer = animation.playerStates(1, position);

    playerPosition.x -= velocityPlayer;
}

void Movements::jump(sf::RenderWindow * position) {
    if (!isJumping) {
        statesPlayer = animation.playerStates(2, position); 
        jumpVelocity = -10.0f;
        isJumping = true;
    }
}

void Movements::update(float deltaTime) {
    
    playerPosition.x += velocityPlayer * deltaTime;
    playerPosition.y += jumpVelocity * deltaTime;

    
    jumpVelocity += 0.5f * deltaTime;
    if (playerPosition.y > 0) {
        playerPosition.y = 0;
        jumpVelocity = 0;
        isJumping = false;
    }
}

void Movements::handleInput(const sf::Event &event, sf::RenderWindow * screen) {
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