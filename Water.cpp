#include "Water.h"
#include "Map.h"

void Water::step(Map &map) {
    if(m_stepped) return;

    stepTo(map, m_x, m_y+1);
    stepTo(map, m_x+m_dir, m_y+1);
    stepTo(map, m_x+m_dir, m_y+1);
    stepTo(map, m_x+m_dir, m_y);
    stepTo(map, m_x+m_dir, m_y);

    if(!m_stepped) m_dir *= -1;

    m_stepped = true;
}

bool Water::canStepTo(Element *element) {
    return element->getType() == ElementType::VOID;
}