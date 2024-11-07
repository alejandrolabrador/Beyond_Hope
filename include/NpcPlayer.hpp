#define NPC_PLAYER_HPP

#ifndef PLAYER_HPP
#include <Player.hpp>
#endif

class NpcPlayer : public Player {
public: 
    NpcPlayer(const std::string &file);
    void updateStatus();
    bool dead();
    void update(float deltaTime);  
    void handleInput(const sf::Event &event, sf::RenderWindow * screen);  
    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override; 

protected:
    
    void moveRight(); 
    void moveLeft(); 
    void jump();
    void jumpRight();
    void jumpLeft();
    sf::Vector2f NpcPlayerPosition; 
    void updateSpritePosition();
    float velocityNpcPlayer; 
    float jumpVelocity;
    bool isJumping; 
    int jumpFrame; 
    int currentPosition; 
    sf::Sprite spriteNpcPlayer;
    sf::Texture textureNpcPlayer;
    std::vector<sf::Sprite> statesNpcPlayer;
    std::vector<sf::Texture> NpcPlayerTextures;
    std::vector<sf::Texture *> states;  
    AssetsManager assets; 
    Animation animation;
    
};