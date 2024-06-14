#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "definitions.h"
#include "Spawner.h"
#include "Map.h"

int main() {
    srand(time(0));
    rand();

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SandBox");
    window.setFramerateLimit(60);

    Map map;
    Spawner spawner(Element::ElementType::VOID, false);
    int radius = 0;
    bool isPressed = false;

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed) isPressed = true;
            if(event.type == sf::Event::MouseButtonReleased) isPressed = false;
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::A)
                    if(radius>0) radius--;
                if(event.key.code == sf::Keyboard::S)
                    spawner.setAdder(!spawner.getAdder());
                if(event.key.code == sf::Keyboard::D)
                    radius++;
                if(event.key.code == sf::Keyboard::Num1)
                    spawner.setType(Element::SAND);
                if(event.key.code == sf::Keyboard::Num2)
                    spawner.setType(Element::WATER);
                if(event.key.code == sf::Keyboard::Num3)
                    spawner.setType(Element::SMOKE);
                if(event.key.code == sf::Keyboard::Num4)
                    spawner.setType(Element::FIRE);
                if(event.key.code == sf::Keyboard::Num5)
                    spawner.setType(Element::STONE);
            }
        }

        if(isPressed) {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int x = pos.x/(screenWidth/mapSize);
            int y = pos.y/(screenWidth/mapSize);
            spawner.spawn(map, x, y, radius);
        }

        window.clear(sf::Color::Black);
        map.tick();
        map.draw(window);
        window.display();

    }

}
