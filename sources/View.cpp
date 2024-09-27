#include <View.hpp>


void View::viewCharacter(sf::Sprite * target, sf::Sprite * map){

    auto && getPosition = target->getPosition(); 
    sf::Vector2f viewCenter = getPosition;

    this->setCenter(viewCenter); 

    this->updateViewBounds(map);
   
}

void View::updateViewBounds(sf::Sprite * map) {

    sf::FloatRect viewRect = sf::FloatRect(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2,
                                           view.getSize().x, view.getSize().y);
    sf::FloatRect mapRect = map->getGlobalBounds();

    float viewCenterY = mapRect.top + mapRect.height - view.getSize().y / 2;
    std::cout << viewCenterY << '\n';
    view.setCenter(view.getCenter().x, viewCenterY);
    std::cout << "Nueva posición del centro de la vista: " << view.getCenter().x << ", " << view.getCenter().y << std::endl;

    if (viewRect.left < mapRect.left) {
        view.setCenter(mapRect.left, view.getCenter().y);
        
    } else if (viewRect.left + viewRect.width > mapRect.left + mapRect.width) {
        view.setCenter(mapRect.left + mapRect.width - viewRect.width, view.getCenter().y);
    }
}