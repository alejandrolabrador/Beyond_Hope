#include <Inventory.hpp>

Inventory::Inventory(const std::string& file): NpcPlayer(file), livesPosition(0, 82), foodPosition(0, 164){

    addItem(items::food, 3);
    addItem(items::medicine, 3);
    textureLives = {assets.useTexture(file)};
    textureFood = {assets.useTexture("/inventory/can/3fullCan.png")};
    spritesLives.setTexture(textureLives);
    spritesFood.setTexture(textureFood);
    spritesFood.setScale(0.8f, 0.8f);  
    spritesLives.setScale(0.8f, 0.8f); 
    spritesFood.setPosition(foodPosition); 
    spritesLives.setPosition(livesPosition); 
}

void Inventory::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(spritesLives, states);
    target.draw(spritesFood, states);
}


void Inventory::addItem(items item, int quantity) {
        
        for (auto& tuple : quantityItems) {
            if (std::get<0>(tuple) == item) {
                
                std::get<1>(tuple) += quantity;
                return;
            }
        }
        
        quantityItems.push_back(std::make_tuple(item, quantity));
    }

void Inventory::quitItem(items item, int quantity) {
    
    for(auto& tuple: quantityItems){

        if(std::get<0>(tuple) == item){

            std::get<1>(tuple) -= quantity; 
            return; 
        }

    }    
}

int Inventory::getItemQuantity(items item) const{

  for(auto& tuple: quantityItems){

    if(std::get<0>(tuple) == item){

        return std::get<1>(tuple); 
    }
  }

}

void Inventory::updateInventoryView(int position){

    livesPosition.x+= position; 
}

void Inventory::updateSprite(items item){

amountInventory = { getItemQuantity(item)};

item == items::medicine ? inventoryTextures = {animation.inventoryStates(0)} : inventoryTextures = {animation.inventoryStates(1)};

if(item == items::medicine){

        spritesLives.setTexture(inventoryTextures[amountInventory]);
        spritesLives.setPosition(livesPosition);
  }

else{
        spritesFood.setTexture(inventoryTextures[amountInventory]);
        spritesFood.setPosition(foodPosition);
}
}