#include <Animation.hpp>

std::map<unsigned int, std::vector<sf::Sprite>> Animation::spriteCache;

std::vector<sf::Sprite> Animation::playerStates(unsigned int movement){
   
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
        sprites.emplace_back(sprite);
    }

    spriteCache[movement] = sprites; 

    return sprites;
}

