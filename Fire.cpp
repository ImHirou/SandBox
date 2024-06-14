#include "Fire.h"
#include "Map.h"

void Fire::step(Map &map) {
    Element::step(map);
    if(m_stepped) return;
    if(m_temperature <= 0) {
        map.deleteElement(m_x, m_y);
        return;
    }
    if(m_temperature > 255) m_color = sf::Color(255, 10, 10);
    else m_color = sf::Color(m_temperature, 10, 10);
    int m_rand = rand() % 3;
    int xdiff = 0;

    if(m_rand == 0) xdiff = 1;
    else if(m_rand == 1) xdiff = 0;
    else xdiff = -1;

    m_rand = rand() % 3;
    int ydiff = 0;

    if(m_rand == 0) ydiff = 1;
    else if(m_rand == 1) ydiff = 0;
    else ydiff = -1;

    stepTo(map, m_x+xdiff, m_y+ydiff);
    stepTo(map, m_x+xdiff, m_y+ydiff);

    m_temperature -= 1;
    m_stepped = true;
}

bool Fire::canStepTo(Element* element) {
    return element->getType() == ElementType::VOID ||
           element->getType() == ElementType::WATER ||
           element->getType() == ElementType::SMOKE;
}