#include "Spawner.h"
#include "Sand.h"
#include "Water.h"
#include "Smoke.h"
#include "Fire.h"

void Spawner::setType(Element::ElementType type) { m_type = type; }

Element::ElementType Spawner::getType() const { return m_type; }

void Spawner::spawn(Map &map, int x, int y, int radius=0) {
    for(int mx=x-radius; mx<=x+radius; ++mx) {
        for(int my=y-radius; my<=y+radius; ++my) {
            if(!Map::inMapBound(mx, my)) continue;
            if(m_type == Element::SAND) map.setElement(new Sand(mx, my), mx, my);
            else if(m_type == Element::WATER) map.setElement(new Water(mx, my), mx, my);
            else if(m_type == Element::SMOKE) map.setElement(new Smoke(mx, my), mx, my);
            else if(m_type == Element::FIRE) map.setElement(new Fire(mx, my), mx, my);
        }
    }
}