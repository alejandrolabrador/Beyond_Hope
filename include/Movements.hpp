#define MOVEMENTS_HPP

#include <AssetsManager.hpp>
class Movements{

public:

void moveDown(sf::Time &); 
void moveUp(sf::Time &); 
void moveRight(sf::Time &);
void moveLeft(sf::Time &);
void Jump(sf::Time &);   

private:

enum class keysMovements : bool{

    /*W,
    D,
    A,
    S, 
    spaceBar*/
};

float velocityPlayer; 


};