#ifndef SANDBOX_ELEMENT_H
#define SANDBOX_ELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class Map;

class Element {
public:
    enum ElementType {
        VOID,
        SAND,
        WATER,
        SMOKE,
        TOTAL_ELEMENTS
    };
protected:
    int m_x;
    int m_y;
    bool m_stepped;
    ElementType m_type;
public:
    Element() : m_x(-1), m_y(-1), m_type(VOID) {}
    Element(int x, int y, ElementType type) : m_x(x), m_y(y), m_type(type) {}

    virtual ~Element() = default;

    void setX(int x);
    void setY(int y);
    void setStepped(bool s);
    void setType(ElementType type);

    int getX() const;
    int getY() const;
    bool isStepped() const;
    ElementType getType() const;

    virtual void step(Map& map);
    void stepTo(Map& map, int x, int y);
    virtual bool canStepTo(Element* element);
    virtual void draw(sf::RenderWindow& window);

};


#endif //SANDBOX_ELEMENT_H
