#include "Stone.h"

void Stone::step(Map &map) {
    if(m_stepped) return;

    m_stepped = true;
}

bool Stone::canStepTo(Element* element) {
    return false;
}