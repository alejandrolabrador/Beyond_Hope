#define INVENTORY_HPP

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.hpp>
#endif

#ifndef ANIMATION_HPP
#include <Animation.hpp>
#endif

class Inventory: public sf::Drawable {

public:

enum class items{

food, 
medicine, 

};

Inventory(){}; 
Inventory(const std::string& file);

void addItem(items item, int quantity);
void removeItem(items item, int quantity);
int getItemQuantity(items item) const;
void updateSprite(items item);
void updateInventoryView(sf::Vector2f view, sf::Vector2f originalView);
std::vector<items> getItems()const;
void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override;

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

}; 

