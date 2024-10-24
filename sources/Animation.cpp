#include <Animation.hpp>

std::map<unsigned int, std::vector<sf::Sprite>> Animation::spriteCache;

//Dont pay attention to this function, cause its not useful. It's just here existing.
std::vector<sf::Sprite> Animation::playerSprites(unsigned int movement){
   
    if (spriteCache.count(movement) > 0) {
        return spriteCache[movement];
    }

    std::vector<sf::Texture> frames;
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
    }  

    fullPath = assetsFolder + internalFolder;

    for (const auto& entry : std::filesystem::directory_iterator(fullPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            std::string filename = entry.path().filename().string();
            texture = assets.useTexture(internalFolder + "/" + filename);
            frames.emplace_back(texture);
        }
    }

    std::vector<sf::Sprite> sprites;
    

    for (const auto frame: frames){
        
        sf::Sprite sprite;
        sprite.setTexture(frame);
        sprite.setScale(0.5f, 0.5f);
        sprites.emplace_back(sprite);
    }

    spriteCache[movement] = sprites; 

    return sprites;
}

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

    switch(movement) {
        case 0:
            internalFolder = "/antonio/Right"; 
            break;
        case 1:
            internalFolder = "/antonio/Left";
            break;
        case 2:
            internalFolder = "/antonio/jumpingRight"; 
            break;
        default:
            std::cout << "Movimiento no reconocido: " << movement << std::endl;
            return textures; // Retornar vacío si el movimiento no es válido
    }  

    fullPath = assetsFolder + internalFolder;

    
    int loadedTexturesCount = 0;

    for (const auto& entry : std::filesystem::directory_iterator(fullPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            std::string filename = entry.path().filename().string();
            texture = assets.useTexture(internalFolder + "/" + filename);
            if (texture.getSize().x == 0) { 
                std::cout << "Error al cargar la textura: " << filename << std::endl;
            } else {
                textures.emplace_back(texture);
                loadedTexturesCount++;
            }
        }
    }

    
    std::cout << "Texturas cargadas para movimiento " << movement << ": " << loadedTexturesCount << std::endl;

    textureCache[movement] = textures; 

    return textures;
}

std::map<unsigned int, std::vector<sf::Texture>> Animation::textureInventoryCache;

std::vector<sf::Texture> Animation::inventoryStates(unsigned int inventoryResource){
   
    if (textureInventoryCache.count(inventoryResource) > 0) {

        return textureCache[inventoryResource];
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

    for (const auto& entry : std::filesystem::directory_iterator(fullPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            std::string filename = entry.path().filename().string();
            texture = assets.useTexture(internalFolder + "/" + filename);

            textures.emplace_back(texture);
        
        }
    }

    textureCache[inventoryResource] = textures; 

    return textures;
}

