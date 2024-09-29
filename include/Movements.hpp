#define MOVEMENTS_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

#ifndef ANIMATION_HPP
#include <Animation.hpp>
#endif


class Movements{

public:

Movements(); 
void moveRight(sf::RenderWindow * position);
void moveLeft(sf::RenderWindow * position);
void jump(sf::RenderWindow * position);   
void update(float deltaTime);
void handleInput(const sf::Event &event, sf::RenderWindow * screen);

enum class states: unsigned int{

    
    moveRight,
    moveLeft,
    jump,

};

private:
 
 std::vector<sf::Sprite> statesPlayer; 
 float velocityPlayer;
 float jumpVelocity;
 sf::Vector2f playerPosition;
 bool isJumping;
 AssetsManager assets;
 Animation animation; 

}; 

