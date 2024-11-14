#include <Maps.hpp>

Maps::Maps(const std::string & file): bluePosition(4392, 390), redPosition(4730, 390){

blueDoorTextures = animation.doorStates(0); 
textureBlueDoor = blueDoorTextures[0]; 
redDoorTextures = animation.doorStates(1);
textureRedDoor = redDoorTextures[0];

spriteBlueDoor.setTexture(textureBlueDoor);
spriteRedDoor.setTexture(textureRedDoor);
spriteRedDoor.setPosition(redPosition);
spriteBlueDoor.setPosition(bluePosition);

}

std::map<unsigned int, sf::Texture> Maps::setMaps (){
 
    std::string fullPath  { "assets/maps"};

    std::vector<std::string> filenames;

for (const auto& entry : std::filesystem::directory_iterator(fullPath)) {
    if (entry.is_regular_file() && entry.path().extension() == ".png") {
        filenames.push_back(entry.path().filename().string());
    }
}

std::sort(filenames.begin(), filenames.end());

for (const auto& filename : filenames) {
    sf::Texture map = assets.useTexture("/maps/" + filename);
    mapTree.emplace(priority, map);
    ++priority;
}
   return mapTree; 
}

void Maps::updateDoor(sf::Vector2f playerPosition){

    if(playerPosition.x >= bluePosition.x - 113.5 && playerPosition.x < bluePosition.x + 113.5){
        
        if(redDoorOpen){

            textureRedDoor = redDoorTextures[0];
            spriteRedClosed.setTexture(textureRedDoor);
            spriteRedClosed.setPosition(redPosition); 
            spriteRedDoor = spriteRedClosed;   
            redDoorOpen = false; 

        }

        blueDoorOpen = true; 
    }
    if(playerPosition.x >= redPosition.x - 113.5 && playerPosition.x < redPosition.x + 113.5){
        
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
       
        textureRedDoor = redDoorTextures[1];
        doorRedOpen.setTexture(textureRedDoor);
        doorRedOpen.setScale(1.95f, 1.95f);
        doorRedOpen.setPosition(redPosition);
        spriteRedDoor = doorRedOpen; 
   
    }

}
int Maps::updateLevel(unsigned int map, sf::Vector2f playerPosition){

    if(blueDoorOpen && playerPosition.x >= bluePosition.x && playerPosition.x < bluePosition.x + 250){

        if (map >= 3){
            return 0; 
        }
        return 1; 
    }

    if(redDoorOpen && playerPosition.x >= redPosition.x && playerPosition.x < redPosition.x + 250){
 
       switch(map){
       
       case 0:
       return 2;
       case 1:
       return 1; 
       case 2:
       return 1; 
       default:
       return 0;
       }
    }
    return map;
}

void Maps::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    target.draw(spriteBlueDoor, states);
    target.draw(spriteRedDoor, states);  
}