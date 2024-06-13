#include <SFML/Graphics.hpp>
#include <iostream>
#include "definitions.h"
#include "Sand.h"
#include "Water.h"
#include "Map.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SandBox");
    window.setFramerateLimit(60);

    Map map;

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                int mx = pos.x/(screenWidth/mapSize);
                int my = pos.y/(screenWidth/mapSize);
                if(event.mouseButton.button == sf::Mouse::Left) map.setElement(new Sand(mx, my), mx, my);
                if(event.mouseButton.button == sf::Mouse::Right) map.setElement(new Water(mx, my), mx, my);
            }
        }

        window.clear(sf::Color::Black);
        map.tick();
        map.draw(window);
        window.display();

    }

}
