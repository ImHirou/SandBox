#include <SFML/Graphics.hpp>
#include "Element.h"
#include "Map.h"
#include "definitions.h"

int Element::getX() const { return m_x; }
int Element::getY() const { return m_y; }
bool Element::isStepped() const { return m_stepped; }
Element::ElementType Element::getType() const { return m_type; }
int Element::getTemperature() const { return m_temperature; }

void Element::setX(int x) { m_x = x; }
void Element::setY(int y) { m_y = y; }
void Element::setStepped(bool s) { m_stepped = s; }
void Element::setType(Element::ElementType type) { m_type = type; }
void Element::setTemperature(int t) { m_temperature = t; }

void Element::draw(sf::RenderWindow &window) {
    sf::RectangleShape rect;
    int xs = screenWidth/mapSize;
    int ys = screenHeight/mapSize;
    rect.setSize(sf::Vector2f(xs, ys));
    rect.setPosition(xs*m_x, ys*m_y);
    rect.setFillColor(m_color);
    window.draw(rect);
}

void Element::step(Map &map) {
    if(m_stepped) return;
    for(int x=m_x-1; x<=m_x+1; ++x) {
        for(int y=m_y-1; y<=m_y+1; ++y) {
            if(x==m_x && y==m_y) continue;
            if(!Map::inMapBound(x, y)) continue;
            if(map.getElement(x, y)->getType() == ElementType::VOID) continue;
            Element* el = map.getElement(x, y);
            el->setTemperature(el->getTemperature()+m_temperature/8);
            m_temperature-=m_temperature/8;
        }
    }
}
void Element::stepTo(Map &map, int x, int y) {
    if(!Map::inMapBound(x, y)) return;
    if(m_stepped) return;
    if(canStepTo(map.getElement(x, y))) {
        m_stepped = true;
        map.swapElements(m_x, m_y, x, y);
    }
}
bool Element::canStepTo(Element* element) { return false; }