#define INVENTORY_HPP

#include <vector>

#ifndef ASSETS_MANAGER_HPP
#include <AssetsManager.cpp>
#endif

class Inventory {

public:

void addItem(items item, int quantity);
void quitItem(items item, int quantity);
int getItemQuantity(items item) const;
void addNewOne(sf::Sprite * map); 

std::vector<items> getItems()const;

private:

std::vector<std::tuple<items, int>> quantityItems;

}; 

enum class items{

food, 
medicine, 

};