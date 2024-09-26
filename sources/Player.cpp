#include <Player.hpp>

sf::Sprite & Player::setPlayer(const std::string & file) {

    texturePlayer =assets.useTexture(file);
    spritePlayer.setTexture(texturePlayer); 
    spritePlayer.setScale(0.5f, 0.5f); 
     
    return spritePlayer; 
}