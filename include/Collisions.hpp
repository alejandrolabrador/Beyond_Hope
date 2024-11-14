#define EVENTS_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

#ifndef ANIMATION_HPP
#include <Animation.hpp>
#endif

#ifndef PLAYER_HPP
#include <Player.hpp>
#endif

class Collisions: public sf::Drawable{

public: 

Collisions(sf::Image & imageCollision); 
bool crackCollision(const std::unique_ptr<Player>& player, const sf::Image& crack, const sf::Color& targetColor); 
void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private: 

sf::Texture collisionTexture; 
sf::Sprite collisionSprite; 
std::vector<sf::Image> cracks; 
AssetsManager assets; 
Animation animation; 
sf::Image collisionImage; 


};