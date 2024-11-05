#define NPC_PLAYER_HPP

#ifndef PLAYER_HPP
#include <Player.hpp>
#endif

class NpcPlayer : public Player {
public: 
    NpcPlayer(const std::string &file);
    void update(float deltaTime); 
    void moveRight(); 
    void moveLeft(); 
    void jump(); 
    void handleInput(const sf::Event &event, sf::RenderWindow * screen);  

private:
    sf::Vector2f playerPosition; 
    void updateSpritePosition();
    float velocityPlayer; 
    float jumpVelocity;
    bool isJumping; 
    int jumpFrame; 
    int currentPosition; 
    std::vector<sf::Texture> playerTextures; 
    std::vector<sf::Sprite> statesPlayer;
    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override; 
};


