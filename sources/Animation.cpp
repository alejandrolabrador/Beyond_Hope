#include <Animation.hpp>

std::map<unsigned int, std::vector<sf::Texture>> Animation::textureCache;

std::vector<sf::Texture> Animation::playerStates(unsigned int movement){
   
    if (textureCache.count(movement) > 0) {

        return textureCache[movement];
    }

    std::vector<sf::Texture> textures;
    std::string assetsFolder {"assets"}; 
    std::string internalFolder; 
    std::string fullPath; 
    sf::Texture texture;

    switch(movement){
        case 0:
            internalFolder = "/antonio/Right"; 
            break;
        case 1:
            internalFolder = "/antonio/Left";
            break;
        case 2:
            internalFolder = "/antonio/jumpingRight"; 
            break;
        case 3:
            internalFolder = "/antonio/jumpingLeft";
    }  

    fullPath = assetsFolder + internalFolder;
      
    std::vector<std::string> filenames;
    filenames = sortFrames(fullPath);
    

    for (const auto& filename : filenames) {

        texture = assets.useTexture(internalFolder + "/" + filename);
        textures.emplace_back(texture);
    }

    textureCache[movement] = textures; 

    return textures;
}

std::map<unsigned int, std::vector<sf::Texture>> Animation::textureInventoryCache;

std::vector<sf::Texture> Animation::inventoryStates(unsigned int inventoryResource){
   
    if (textureInventoryCache.count(inventoryResource) > 0) {

        return textureInventoryCache[inventoryResource];
    }

    std::vector<sf::Texture> textures;
    std::string assetsFolder {"assets"}; 
    std::string internalFolder; 
    std::string fullPath; 
    sf::Texture texture;

    switch(inventoryResource){
        case 0:
            internalFolder = "/inventory/life"; 
            break;
        case 1:
            internalFolder = "/inventory/can";
            break;

    }  

    fullPath = assetsFolder + internalFolder;

    std::vector<std::string> filenames;
    filenames = sortFrames(fullPath);
    

    for (const auto& filename : filenames) {

            texture = assets.useTexture(internalFolder + "/" + filename);
            textures.emplace_back(texture);
    }

    textureInventoryCache[inventoryResource] = textures; 

    return textures;
}
std::map<unsigned int, std::vector<sf::Texture>> Animation::textureDoorCache; 

std::vector<sf::Texture> Animation::doorStates(unsigned int color){

 if (textureDoorCache.count(color) > 0) {

        return textureDoorCache[color];
    }

    std::vector<sf::Texture> textures;
    std::string assetsFolder {"assets"}; 
    std::string internalFolder; 
    std::string fullPath; 
    sf::Texture texture;

    switch(color){
        case 0:
            internalFolder = "/doors/blue"; 
            break;
        case 1:
            internalFolder = "/doors/red";
            break;

    }  

    fullPath = assetsFolder + internalFolder;
    
      std::vector<std::string> filenames;
      filenames = sortFrames(fullPath);
    

    for (const auto& filename : filenames) {

            texture = assets.useTexture(internalFolder + "/" + filename);
            textures.emplace_back(texture);
    }

    textureDoorCache[color] = textures; 

    return textures;
    
}
std::map<unsigned int, std::vector<sf::Texture>> Animation::textureNpcCache; 

std::vector<sf::Texture> Animation::npcStates(unsigned int movement) {

    if (textureNpcCache.count(movement) > 0) {
    return textureNpcCache[movement];
}

std::vector<sf::Texture> textures;
std::string assetsFolder {"assets"}; 
std::string internalFolder; 
std::string fullPath; 
sf::Texture texture;

    switch(movement) {
        case 0:
        internalFolder = "/carolina/Right"; 
        break;
        case 1:
        internalFolder = "/carolina/Left";
        break;
        case 2:
        internalFolder = "/carolina/jumpingRight"; 
        break;
        case 3:
        internalFolder = "/carolina/jumpingLeft"; 
        break;
} 

    fullPath = assetsFolder + internalFolder;

    std::vector<std::string> filenames;
    filenames = sortFrames(fullPath);
    
    for (const auto& filename : filenames) {
    
        texture = assets.useTexture(internalFolder + "/" + filename);
        textures.emplace_back(texture);
}

    textureNpcCache[movement] = textures; 
    return textures;
    
} 

std::vector<sf::Image> Animation::collisionStates(){

    std::string fullPath{ "assets/collisions" };
    std::vector<sf::Image> collisions;

    std::vector<std::string> collisionsDirectory = sortFrames(fullPath); 

    for (const auto& level : collisionsDirectory) {
        
        std::string fullFileName = fullPath + "/" + level; 
        collisions.emplace_back(assets.loadCollisions(fullFileName)); // Almacenar directamente
    }
    return collisions; 
}
std::vector<std::string> Animation::sortFrames(std::string fullPath) {

    std::vector<std::string> filenames; 
    for (const auto& entry : std::filesystem::directory_iterator(fullPath)) {
    if (entry.is_regular_file() && entry.path().extension() == ".png") {
        filenames.push_back(entry.path().filename().string());
    }  
}
    std::sort(filenames.begin(), filenames.end());

    return filenames; 
}

