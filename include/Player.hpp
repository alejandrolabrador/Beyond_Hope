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
sf::Vector2f setOriginalPosition(); 
sf::Vector2f getPosition();
sf::Vector2f playerPosition;
sf::Sprite& getSprite();

protected:

sf::Texture texturePlayer; 
float velocityPlayer;
void moveRight();
void moveLeft();
void jump(); 
void jumpLeft(); 
void updateSpritePosition(); 
unsigned int health; 
std::vector<sf::Texture *> states;  
sf::Sprite spritePlayer;
std::vector<sf::Sprite> statesPlayer;
std::vector<sf::Texture> playerTextures;  
float jumpVelocity;

bool isJumping;
AssetsManager assets; 
Animation animation; 
int currentPosition; 
int jumpFrame;
};