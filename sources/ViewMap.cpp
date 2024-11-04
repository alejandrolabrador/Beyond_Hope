#include <ViewMap.hpp>


void ViewMap::viewCharacter(std::unique_ptr<Player>& target, sf::Sprite * map, sf::Vector2u size) {
    
    auto && getPosition = target->getPosition(); 
    sf::Vector2f viewCenter = getPosition;
    view.setCenter(viewCenter);

    this->updateViewBounds(map, size);
}

void ViewMap::updateViewBounds(sf::Sprite * map, sf::Vector2u sizeView) {

   view.setSize(static_cast<float>(sizeView.x), static_cast<float>(sizeView.y));

    sf::FloatRect viewRect = sf::FloatRect(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2, view.getSize().x, view.getSize().y);
    sf::FloatRect mapRect = map->getGlobalBounds();

    float maxYPosition = mapRect.top + mapRect.height - view.getSize().y;

    float viewCenterY = std::min(maxYPosition, mapRect.top + (mapRect.height - 70) - view.getSize().y / 2);
    view.setCenter(view.getCenter().x, viewCenterY);

    if (viewRect.left < mapRect.left) { 
        view.setCenter(mapRect.left + view.getSize().x / 2, view.getCenter().y);

    } else if (viewRect.left + viewRect.width > mapRect.left + mapRect.width) {
        view.setCenter(mapRect.left + mapRect.width - view.getSize().x / 2, view.getCenter().y);
    }

    if (viewRect.top < mapRect.top) {
        view.setCenter(view.getCenter().x, mapRect.top + view.getSize().y / 2);

    } else if (viewRect.top + viewRect.height > mapRect.top + mapRect.height - 70) {
        view.setCenter(view.getCenter().x, mapRect.top + mapRect.height - 70 - view.getSize().y / 2);
    }
}

sf::View ViewMap::getView() const {
    
    
    return view; 
}