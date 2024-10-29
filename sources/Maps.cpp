#include <Maps.hpp>

void Maps::getMap (){
 
    std::string fullPath  { "assets/maps"};

        for (const auto& entry : std::filesystem::directory_iterator(fullPath)) {
        
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            std::string filename = entry.path().filename().string();

            std::unique_ptr<sf::Texture> map = std::make_unique<sf::Texture>(assets.useTexture("/maps/" + filename));
            std::pair<sf::Texture*, unsigned int> pair(map.get(), priority);
            
            mapTree.insert(pair);
            ++priority; 
        }
    }
    
}

void Maps::draw(sf::RenderTarget& target, sf::RenderStates states) const{

}