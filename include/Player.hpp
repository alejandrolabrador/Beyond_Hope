#define PLAYER_HPP


# ifndef ASSETS_MANAGER_HPP
# include <AssetsManager.hpp>
# endif

# ifndef ANIMATION_HPP
# include <Animation.hpp>
# endif


class Player : public sf::Drawable{

public:

Player(const std::string & file); 
void updateStatus();
bool dead(); 
void handleInput(const sf::Event &event, sf::RenderWindow * screen); 
void update(float deltaTime);
void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

void moveRight(sf::RenderWindow * position);
void moveLeft(sf::RenderWindow * position);
void jump(sf::RenderWindow * position); 
void updateSpritePosition(); 

unsigned int health; 
std::vector<sf::Texture *> states;  
sf::Sprite spritePlayer;
sf::Texture texturePlayer; 
std::vector<sf::Sprite> statesPlayer; 
float velocityPlayer;
float jumpVelocity;
sf::Vector2f playerPosition;
bool isJumping;
AssetsManager assets; 
Animation animation; 
int currentPosition; 

};