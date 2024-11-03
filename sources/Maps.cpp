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

std::map<unsigned int, sf::Texture> Maps::setMaps (){
 
    std::string fullPath  { "assets/maps"};

        for (const auto& entry : std::filesystem::directory_iterator(fullPath)) {
        
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            std::string filename = entry.path().filename().string();

            sf::Texture map = assets.useTexture("/maps/" + filename);

            mapTree.emplace(priority, map); 
            std::cout << filename; 
            
        }
        ++priority; 

    }
    
    return mapTree; 
 
}

void Maps::updateDoor(sf::Vector2f playerPosition){

    if(playerPosition.x > bluePosition.x && playerPosition.x < bluePosition.x + 250){
        
        if(redDoorOpen){

            textureRedDoor = redDoorTextures[1];
            spriteRedClosed.setTexture(textureRedDoor);
            spriteRedClosed.setPosition(redPosition); 
            spriteRedDoor = spriteRedClosed;   
            redDoorOpen = false; 

        }

        blueDoorOpen = true; 
    }
    if(playerPosition.x > redPosition.x && playerPosition.x < redPosition.x + 250){
        
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