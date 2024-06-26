#include "Spawner.h"
#include "Sand.h"
#include "Water.h"
#include "Smoke.h"
#include "Fire.h"
#include "Stone.h"

void Spawner::setType(Element::ElementType type) { m_type = type; }
void Spawner::setAdder(bool b) { m_adder = b; }

Element::ElementType Spawner::getType() const { return m_type; }
bool Spawner::getAdder() const { return m_adder; }

void Spawner::spawn(Map &map, int x, int y, int radius=0) {
    for(int mx=x-radius; mx<=x+radius; ++mx) {
        for(int my=y-radius; my<=y+radius; ++my) {
            if(!Map::inMapBound(mx, my)) continue;
            if(!m_adder) {
                if (m_type == Element::SAND) map.setElement(new Sand(mx, my), mx, my);
                else if (m_type == Element::WATER) map.setElement(new Water(mx, my), mx, my);
                else if (m_type == Element::SMOKE) map.setElement(new Smoke(mx, my), mx, my);
                else if (m_type == Element::FIRE) map.setElement(new Fire(mx, my), mx, my);
                else if (m_type == Element::STONE) map.setElement(new Stone(mx, my), mx, my);
            }
            else {
                if (m_type == Element::SAND) map.addElement(new Sand(mx, my), mx, my);
                else if (m_type == Element::WATER) map.addElement(new Water(mx, my), mx, my);
                else if (m_type == Element::SMOKE) map.addElement(new Smoke(mx, my), mx, my);
                else if (m_type == Element::FIRE) map.addElement(new Fire(mx, my), mx, my);
                else if (m_type == Element::STONE) map.addElement(new Stone(mx, my), mx, my);
            }
        }
    }
}