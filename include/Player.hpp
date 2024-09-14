#define PLAYER_HPP

class Player{

public:

void updateStatus();
bool dead();  


private:

unsigned int health; 
std::vector<sf::Texture> states;  

};