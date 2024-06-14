#include <iostream>
#include "Map.h"

Map::Map() {
    m_elements = new Element *[mapSize*mapSize];
    for(int x=0; x<mapSize; ++x) {
        for(int y=0; y<mapSize; ++y) {
            m_elements[x+y*mapSize] = new Element(x, y, Element::VOID);
        }
    }
}

Element** Map::getElements() { return m_elements; }

Element* Map::getElement(int x, int y) {
    return m_elements[x+y*mapSize];
}
void Map::setElement(Element *element, int x, int y) {
    int index = x + y * mapSize;
    delete m_elements[index];
    m_elements[index] = element;
}
void Map::addElement(Element *element, int x, int y) {
    int index = x + y * mapSize;
    if(m_elements[index]->getType() == Element::ElementType::VOID) {
        delete m_elements[index];
        m_elements[index] = element;
    } else {
        delete element;
    }
}

void Map::swapElements(int x1, int y1, int x2, int y2) {
    Element* temp = m_elements[x1+y1*mapSize];
    temp->setX(x2);
    temp->setY(y2);
    m_elements[x2+y2*mapSize]->setX(x1);
    m_elements[x2+y2*mapSize]->setY(y1);
    //setElement(m_elements[x2+y2*mapSize], x1, y1);
    //setElement(temp, x2, y2);
    m_elements[x1+y1*mapSize] = m_elements[x2+y2*mapSize];
    m_elements[x2+y2*mapSize] = temp;
}
void Map::deleteElement(int x, int y) {
    delete m_elements[x+y*mapSize];
    m_elements[x+y*mapSize] = new Element(x, y, Element::VOID);
}

void Map::draw(sf::RenderWindow &window) {
    for(int x=0; x<mapSize; ++x) {
        for(int y=0; y<mapSize; ++y) {
            m_elements[x+y*mapSize]->draw(window);
        }
    }
}

void Map::tick() {
    for(int x=0; x<mapSize; ++x) {
        for(int y=0; y<mapSize; ++y) {
            m_elements[x+y*mapSize]->step(*this);
        }
    }
    for(int x=0; x<mapSize; ++x) {
        for(int y=0; y<mapSize; ++y) {
            m_elements[x+y*mapSize]->setStepped(false);
        }
    }
}

bool Map::inMapBound(int x, int y) {
    return  (x>=0 && x<mapSize &&
            y>=0 && y<mapSize);
}

