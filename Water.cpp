#include "Water.h"
#include "Smoke.h"
#include "Map.h"

void Water::step(Map &map) {
    if(m_stepped) return;
    if(m_temperature >= 60) {
        map.setElement(new Smoke(m_x, m_y), m_x, m_y);
        return;
    }

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