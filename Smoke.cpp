#include "Smoke.h"
#include "Map.h"
#include "Water.h"

void Smoke::step(Map &map) {
    Element::step(map);
    if(m_stepped) return;
    if(m_lifeTime <=0) {
        map.deleteElement(m_x, m_y);
        map.setElement(new Water(m_x, m_y), m_x, m_y);
        return;
    }
    m_color = sf::Color(m_lifeTime, m_lifeTime, m_lifeTime);
    if(rand() % 10 < 3) stepTo(map, m_x, m_y-1);
    int diff=1;
    if(rand() % 2 == 1) diff=-1;
    stepTo(map, m_x+diff, m_y-1);
    stepTo(map, m_x+diff, m_y-1);
    stepTo(map, m_x+diff, m_y);
    stepTo(map, m_x+diff, m_y);

    m_lifeTime--;
    m_stepped = true;
}

bool Smoke::canStepTo(Element *element) {
    return element->getType() == ElementType::VOID ||
            element->getType() == ElementType::WATER ||
            element->getType() == ElementType::FIRE;
}