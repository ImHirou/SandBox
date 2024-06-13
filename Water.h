#ifndef SANDBOX_WATER_H
#define SANDBOX_WATER_H

#include "Element.h"

class Water : public Element{
private:
    int m_dir=1;
public:
    Water() : Element(-1, -1, ElementType::WATER) {}
    Water(int x, int y) : Element(x, y, ElementType::WATER) {
        m_color = sf::Color(10 + rand() % 20, 10 + rand() % 20, 180 + rand() % 30);}

    virtual void step(Map &map);
    virtual bool canStepTo(Element* element);

};


#endif //SANDBOX_WATER_H
