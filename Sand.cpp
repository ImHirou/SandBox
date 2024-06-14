#include <cstdlib>
#include "Sand.h"
#include "Map.h"

void Sand::step(Map &map) {
    if(m_stepped) return;

    stepTo(map, m_x, m_y+1);
    int diff=1;
    if(rand() % 10 < 5) diff=-1;
    stepTo(map, m_x+diff, m_y+1);
    stepTo(map, m_x+diff, m_y+1);

    m_stepped = true;
}

bool Sand::canStepTo(Element* element) {
    return element->getType() == ElementType::VOID ||
           element->getType() == ElementType::WATER ||
           element->getType() == ElementType::SMOKE ||
           element->getType() == ElementType::FIRE;
}