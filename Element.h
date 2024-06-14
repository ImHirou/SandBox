#ifndef SANDBOX_ELEMENT_H
#define SANDBOX_ELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>

class Map;

class Element {
public:
    enum ElementType {
        VOID,
        SAND,
        WATER,
        SMOKE,
        FIRE,
        TOTAL_ELEMENTS
    };
protected:
    int m_x;
    int m_y;
    bool m_stepped = false;
    sf::Color m_color;
    ElementType m_type;
public:
    Element() : m_x(-1), m_y(-1), m_color(sf::Color::Black), m_type(VOID) {}
    Element(int x, int y, ElementType type) : m_x(x), m_y(y), m_color(sf::Color::Black), m_type(type) {}

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
