#include <Collisions.hpp>

Collisions::Collisions(sf::Image & imageCollision){

collisionTexture.loadFromImage(imageCollision);
collisionSprite.setTexture(collisionTexture);
collisionSprite.setPosition(0, 0);

}

bool Collisions::crackCollision(const std::unique_ptr<Player>& player){
    
     sf::Sprite& playerSprite = player->getSprite();

        sf::Vector2f position = playerSprite.getPosition();
        int x = static_cast<int>(position.x);
        int y = static_cast<int>(position.y);
        const std::shared_ptr<sf::Image> cracks = getImage();
        if (x < 0 || x >= cracks->getSize().x || y < 0 || y >= cracks->getSize().y) {
            return false; 
        }

        sf::Color pixelColor = cracks->getPixel(x, y);
         
        return (pixelColor == sf::Color::Red);
}



std::shared_ptr<sf::Image> Collisions::getImage() const{

    return std::make_shared<sf::Image>(collisionTexture.copyToImage());
}


void Collisions::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(collisionSprite, states);
    
}

/*bool Collisions::crackCollision(const std::unique_ptr<Player>& player, std::unique_ptr<Collisions>& cracks){
    
    // Obtener el sprite del jugador
    sf::Sprite& playerSprite = player->getSprite();

    // Obtener la posición del sprite
    sf::Vector2f position = playerSprite.getPosition();
    int x = static_cast<int>(position.x);
    int y = static_cast<int>(position.y);
    if (x < 0 || x >= cracks.getSize().x || y < 0 || y >= cracks.getSize().y) {

        return false; 
    }

    // Obtener el color del píxel en la posición del sprite
    sf::Color pixelColor = cracks.getPixel(x, y);
    std::cout << pixelColor.toInteger() << "\n"; 

    // Comprobar si el color coincide con el color de la grieta (por ejemplo, rojo)
    return (pixelColor == sf::Color::Red);
}*/