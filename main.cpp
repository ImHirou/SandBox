#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "definitions.h"
#include "Sand.h"
#include "Water.h"
#include "Smoke.h"
#include "Map.h"

int main() {
    srand(time(0));
    rand();

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SandBox");
    window.setFramerateLimit(60);

    Map map;
    bool isPressed = false;
    int radius = 0;
    int type = 0;

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
                if(event.key.code == sf::Keyboard::D)
                    radius++;
                if(event.key.code == sf::Keyboard::Num1)
                    type = 1;
                if(event.key.code == sf::Keyboard::Num2)
                    type = 2;
                if(event.key.code == sf::Keyboard::Num3)
                    type = 3;
            }
        }

        if(isPressed) {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int mx = pos.x/(screenWidth/mapSize);
            int my = pos.y/(screenWidth/mapSize);
            for(int x=mx-radius; x<=mx+radius; ++x) {
                for(int y=my-radius; y<=my+radius; ++y) {
                    if(!Map::inMapBound(x, y)) continue;
                    if(type == 1) map.setElement(new Sand(x, y), x, y);
                    else if(type == 2) map.setElement(new Water(x, y), x, y);
                    else if(type == 3) map.setElement(new Smoke(x, y), x, y);
                }
            }
        }

        window.clear(sf::Color::Black);
        map.tick();
        map.draw(window);
        window.display();

    }

}
