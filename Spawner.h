#ifndef SANDBOX_SPAWNER_H
#define SANDBOX_SPAWNER_H

#include "Map.h"

class Spawner {
private:
    Element::ElementType m_type;
    bool m_adder=false;
public:
    Spawner() : m_type(Element::VOID) {}
    Spawner(Element::ElementType type, bool adder) : m_type(type), m_adder(adder) {}

    void setType(Element::ElementType type);

    Element::ElementType getType() const;

    void spawn(Map& map, int x, int y, int radius);

};


#endif //SANDBOX_SPAWNER_H
