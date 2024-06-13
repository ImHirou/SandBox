#ifndef SANDBOX_SAND_H
#define SANDBOX_SAND_H

#include "Element.h"

class Sand : public Element {
public:
    Sand() : Element(-1, -1, ElementType::SAND) {}
    Sand(int x, int y) : Element(x, y, ElementType::SAND) {
        m_color = sf::Color(170 + rand() % 20, 170 + rand() % 20, 20 + rand() % 10);
    }

    virtual void step(Map &map);
    virtual bool canStepTo(Element* element);

};


#endif //SANDBOX_SAND_H
