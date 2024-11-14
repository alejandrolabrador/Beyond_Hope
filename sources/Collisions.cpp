#include <Collisions.hpp>

Collisions::Collisions(sf::Image & imageCollision){

collisionImage = imageCollision; 
collisionTexture.loadFromImage(imageCollision);
collisionSprite.setTexture(collisionTexture);
collisionSprite.setPosition(0, 0);

}

bool Collisions::crackCollision(const std::unique_ptr<Player>& player, const sf::Image& collisionImage, const sf::Color& targetColor) {

    sf::Sprite& spritePlayer = player->getSprite();
    sf::FloatRect bounds = spritePlayer.getGlobalBounds();
    
    int x = static_cast<int>(bounds.left);
    int y = static_cast<int>(bounds.top);

    if (x < 0 || y < 0 || x >= collisionImage.getSize().x || y >= collisionImage.getSize().y) {
        return false;
    }
    
    sf::Color color = collisionImage.getPixel(x, y);

    sf::Color pixelColor = collisionImage.getPixel(x + 100, ((y*1.5)-34));

    return (pixelColor == targetColor);
}

void Collisions::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(collisionSprite, states);
    
}
