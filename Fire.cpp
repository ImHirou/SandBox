#include "Fire.h"
#include "Map.h"

void Fire::step(Map &map) {
    Element::step(map);
    if(m_stepped) return;
    if(m_temperature <= 0) {
        map.deleteElement(m_x, m_y);
        return;
    }
    m_color = sf::Color(m_temperature, 10, 10);
    int m_rand = rand() % 12;
    int xdiff = 0;

    if(m_rand < 4) xdiff = -1;
    else if(m_rand < 8) xdiff = 0;
    else xdiff = 1;

    m_rand = rand() % 12;
    int ydiff = 0;

    if(m_rand < 4) ydiff = -1;
    else if(m_rand < 8) ydiff = 0;
    else ydiff = 1;

    stepTo(map, m_x+xdiff, m_y+ydiff);
    stepTo(map, m_x+xdiff, m_y+ydiff);

    m_temperature -= rand() % 5;
    m_stepped = true;
}

bool Fire::canStepTo(Element* element) {
    return element->getType() == ElementType::VOID ||
           element->getType() == ElementType::WATER ||
           element->getType() == ElementType::SMOKE;
}