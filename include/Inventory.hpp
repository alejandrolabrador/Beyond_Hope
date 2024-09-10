#define INVENTORY_HPP

#include <vector>

class Inventory {

public:

void addItem(items item, int quantity);
void quitItem(items item, int quantity);
int getItemQuantity(items item) const;

std::vector<items> getItems()const;

private:

std::vector<std::tuple<items, int>> quantityItems;

}; 

enum class items{

water,
food, 
medicine, 

};