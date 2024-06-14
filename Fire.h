#ifndef SANDBOX_FIRE_H
#define SANDBOX_FIRE_H

#include "Element.h"

class Fire : public Element{
private:
    int m_temperature;
public:
    Fire() : Element(-1, -1, ElementType::FIRE) {}
    Fire(int x, int y) : Element(x, y, ElementType::FIRE), m_temperature(160 + rand() % 40) {
        m_color = sf::Color(m_temperature, 10, 10);
    }

    virtual void step(Map &map);
    virtual bool canStepTo(Element* element);

};


#endif //SANDBOX_FIRE_H
