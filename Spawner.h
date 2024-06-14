#ifndef SANDBOX_SPAWNER_H
#define SANDBOX_SPAWNER_H

#include "Map.h"

class Spawner {
private:
    Element::ElementType m_type;
public:
    Spawner() : m_type(Element::VOID) {}
    Spawner(Element::ElementType type) : m_type(type) {}

    void setType(Element::ElementType type);

    Element::ElementType getType() const;

    void spawn(Map& map, int x, int y, int radius);

};


#endif //SANDBOX_SPAWNER_H
