#include "Button.hpp"

Button::Button()
{
    _status = ACTIVE;
    _shape.setOutlineThickness(1);
    _shape.setOutlineColor(sf::Color::Blue);
    _shape.setFillColor(sf::Color(100, 100, 255));
}

Button::Button(const Button &b)
{
    _shape = b._shape;
    _status = b._status;
}

Button &Button::operator=(const Button &b)
{
    _shape = b._shape;
    _status = b._status;
    return (*this);
}

Button::~Button()
{
}