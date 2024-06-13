#include "Sand.h"
#include "Map.h"

void Sand::step(Map &map) {
    if(m_stepped) return;
    if(m_y+1>=mapSize) return;
    if(canStepTo(map.getElement(m_x, m_y+1))) {
        map.swapElements(m_x, m_y, m_x, m_y+1);
        m_stepped = true;
        return;
    }
    if(m_x-1>=0) {
        if (canStepTo(map.getElement(m_x - 1, m_y + 1))) {
            map.swapElements(m_x, m_y, m_x - 1, m_y + 1);
            m_stepped = true;
            return;
        }
    }
    if(m_x+1<mapSize) {
        if (canStepTo(map.getElement(m_x + 1, m_y + 1))) {
            map.swapElements(m_x, m_y, m_x + 1, m_y + 1);
            m_stepped = true;
            return;
        }
    }
    m_stepped = true;
}

bool Sand::canStepTo(Element* element) {
    return element->getType() == ElementType::VOID || element->getType() == ElementType::WATER;
}