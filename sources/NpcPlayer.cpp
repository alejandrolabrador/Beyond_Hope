#include <NpcPlayer.hpp>

NpcPlayer::NpcPlayer(const std::string & file) : Player(file), playerPosition(40, 493){

    texturePlayer = assets.useTexture(file);
    spritePlayer.setTexture(texturePlayer); 
    spritePlayer.setScale(0.21f, 0.21f); 
    spritePlayer.setPosition(playerPosition);  
}


