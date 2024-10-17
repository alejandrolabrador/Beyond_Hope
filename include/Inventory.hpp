#define INVENTORY_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

#ifndef NPC_PLAYER_HPP
#include <NpcPlayer.hpp>
#endif

#ifndef ANIMATION_HPP
#include <Animation.hpp>
#endif

class Inventory: public NpcPlayer  {

enum class items{

food, 
medicine, 

};

public:

Inventory(const std::string& file);

void addItem(items item, int quantity);
void quitItem(items item, int quantity);
int getItemQuantity(items item) const;
void updateSprite(items item);

std::vector<items> getItems()const;

private:

AssetsManager assets;
Animation animation;
sf::Texture textureLives; 
sf::Sprite spritesLives; 
sf::Texture textureFood;
sf::Sprite spritesFood; 
sf::Vector2f livesPosition; 
sf::Vector2f foodPosition; 
int amountInventory;
std::vector<sf::Texture> inventoryTextures; 
std::vector<std::tuple<items, int>> quantityItems;
void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override;

}; 

