#include <SFML/Graphics.hpp>
#include "Element.h"
#include "definitions.h"

int Element::getX() const { return m_x; }
int Element::getY() const { return m_y; }
bool Element::isStepped() const { return m_stepped; }
Element::ElementType Element::getType() const { return m_type; }

void Element::setX(int x) { m_x = x; }
void Element::setY(int y) { m_y = y; }
void Element::setStepped(bool s) { m_stepped = s; }
void Element::setType(Element::ElementType type) { m_type = type; }

void Element::draw(sf::RenderWindow &window) {
    sf::RectangleShape rect;
    int xs = screenWidth/mapSize;
    int ys = screenHeight/mapSize;
    rect.setSize(sf::Vector2f(xs, ys));
    rect.setPosition(xs*m_x, ys*m_y);
    if(m_type == VOID) {
        rect.setFillColor(sf::Color::Black);
    }
    else if(m_type == SAND) {
        rect.setFillColor(sf::Color::Yellow);
    }
    window.draw(rect);
}

void Element::step(Map &map) {}
bool Element::canStepTo(Element* element) {}