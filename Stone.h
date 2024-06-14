#ifndef SANDBOX_STONE_H
#define SANDBOX_STONE_H

#include "Element.h"

class Stone : public Element{
private:
public:
    Stone() : Element(-1, -1, ElementType::STONE) {}
    Stone(int x, int y) : Element(x, y, ElementType::STONE) {
        int rgb = 125 + rand() % 50;
        m_color = sf::Color(rgb,rgb,rgb);
    }

    virtual void step(Map &map);
    virtual bool canStepTo(Element* element);

};


#endif //SANDBOX_STONE_H
