#include <Maps.hpp>

Maps::Maps(const std::string & file): bluePosition(4392, 390), redPosition(4730, 390){

blueDoorTextures = animation.doorStates(0); 
textureBlueDoor = blueDoorTextures[0]; 
redDoorTextures = animation.doorStates(1);
textureRedDoor = redDoorTextures[1];

spriteBlueDoor.setTexture(textureBlueDoor);
spriteRedDoor.setTexture(textureRedDoor);
spriteRedDoor.setPosition(redPosition);
spriteBlueDoor.setPosition(bluePosition);

}

Maps::mapRankedTreap Maps::setMaps (){
 
    std::string fullPath  { "assets/maps"};

        for (const auto& entry : std::filesystem::directory_iterator(fullPath)) {
        
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            std::string filename = entry.path().filename().string();

            std::unique_ptr<sf::Texture> map = std::make_unique<sf::Texture>(assets.useTexture("/maps/" + filename));
            std::pair<sf::Texture*, unsigned int> pair(map.get(), priority);

            mapTree.insert(pair);
            std::cout << filename; 
            
        }
        ++priority; 

    }
    
    return mapTree; 
 
}

void Maps::updateDoor(sf::Vector2f playerPosition){

    if(playerPosition.x > 4394 && playerPosition.x < 4688){
        
        if(redDoorOpen){

            textureRedDoor = redDoorTextures[1];
            spriteRedClosed.setTexture(textureRedDoor);
            spriteRedClosed.setPosition(redPosition); 
            spriteRedDoor = spriteRedClosed;   
            redDoorOpen = false; 

        }

        blueDoorOpen = true; 
    }
    if(playerPosition.x > 4748 && playerPosition.x < 4945){
        
        if(blueDoorOpen){

            textureBlueDoor = blueDoorTextures[0];
            spriteBlueClosed.setTexture(textureBlueDoor);
            spriteBlueClosed.setPosition(bluePosition); 
            spriteBlueDoor = spriteBlueClosed;   
            blueDoorOpen = false; 
        }
        
        redDoorOpen = true; 
    }
    if(blueDoorOpen && !redDoorOpen){

        textureBlueDoor = blueDoorTextures[1]; 
        doorBlueOpen.setTexture(textureBlueDoor);
        doorBlueOpen.setScale(1.95f, 1.95f);
        doorBlueOpen.setPosition(bluePosition);
        spriteBlueDoor = doorBlueOpen;   
    }
    if(redDoorOpen && !blueDoorOpen){
       
        textureRedDoor = redDoorTextures[0];
        doorRedOpen.setTexture(textureRedDoor);
        doorRedOpen.setScale(1.95f, 1.95f);
        doorRedOpen.setPosition(redPosition);
        spriteRedDoor = doorRedOpen; 
   
    }
    if(redDoorOpen && blueDoorOpen){

    }

}
void Maps::updateLevel(){

}

void Maps::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    target.draw(spriteBlueDoor, states);
    target.draw(spriteRedDoor, states);  
}