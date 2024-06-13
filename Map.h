#ifndef SANDBOX_MAP_H
#define SANDBOX_MAP_H

#include "Element.h"
#include "definitions.h"

class Map {
private:
    Element** m_elements;
public:
    Map();

    ~Map() {
        for(int i=0; i<mapSize*mapSize; i++) {
            delete m_elements[i];
        }
        delete[] m_elements;
    }

    Element** getElements();

    Element* getElement(int x, int y);
    void setElement(Element* element, int x, int y);

    void swapElements(int x1 ,int y1, int x2, int y2);

    void draw(sf::RenderWindow& window);
    void tick();

    static bool inMapBound(int x, int y);

};


#endif //SANDBOX_MAP_H
