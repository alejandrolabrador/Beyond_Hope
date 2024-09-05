#include <main.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>

int main() {

  
  sf::Texture texture;
  
  if (!texture.loadFromFile("assets/antonio/character_static.png")) {

    // Si la carga falla, muestra un mensaje de error 
     throw std::length_error("invalid lol");

    return 1;
  }

  // Crea un objeto sf::Sprite a partir de la textura cargada
  sf::Sprite sprite(texture);

  sprite.setScale(0.5f, 0.5f); 

  // Crea una ventana de SFML
  sf::RenderWindow ventana(sf::VideoMode(1800, 1800), "Mi ventana");

  // Muestra el sprite en la pantalla
  ventana.clear();
  ventana.draw(sprite);
  ventana.display();

  // Espera a que el usuario cierre la ventana
  while (ventana.isOpen()) {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
      if (evento.type == sf::Event::Closed) {
        ventana.close();
      }
    }
  }

  return 0;
}