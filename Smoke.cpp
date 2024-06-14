#include "Smoke.h"
#include "Map.h"

void Smoke::step(Map &map) {
    if(m_stepped) return;
    if(m_lifeTime <=0) {
        map.deleteElement(m_x, m_y);
        return;
    }
    if(rand() % 10 < 3) stepTo(map, m_x, m_y-1);
    int diff=1;
    if(rand() % 10 < 5) diff=-1;
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