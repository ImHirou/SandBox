#ifndef SANDBOX_SMOKE_H
#define SANDBOX_SMOKE_H

#include "Element.h"

class Smoke : public Element{
private:
    int m_lifeTime; //in ticks;
public:
    Smoke() : Element(-1, -1, ElementType::SMOKE), m_lifeTime(160 + rand() % 80) {}
    Smoke(int x, int y) : Element(x, y, ElementType::SMOKE), m_lifeTime(160 + rand() % 80) {
        m_color = sf::Color(m_lifeTime, m_lifeTime, m_lifeTime);
    }

    virtual void step(Map &map);
    virtual bool canStepTo(Element* element);

};


#endif //SANDBOX_SMOKE_H
