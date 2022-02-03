#include "Button.hpp"
#include <iostream>

Button::Button()
{
    _textAlign = CENTER;
    _status = ACTIVE;
    _shape.setOutlineThickness(1);
    _shape.setOutlineColor(sf::Color(100, 100, 255));
    _shape.setFillColor(sf::Color(200, 200, 255));
    _shape.setSize({100, 50});
    _shape.setPosition({0, 0});
    _text.setPosition({0, 0});
    _text.setCharacterSize(16);
    _text.setFillColor(sf::Color::Black);
    _text.setString("Button");
}

Button::Button(std::string fontPath) : Button()
{
    _font.loadFromFile(fontPath);
    _text.setFont(_font);
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

void Button::draw(sf::RenderWindow &window) const
{
    window.draw(_shape);
    window.draw(_text);
    if (_font.getInfo().family == "")
        std::cerr << "No font loaded" << std::endl;
}

sf::RectangleShape &Button::getShape(void)
{
    return (_shape);
}

sf::Text &Button::getText(void)
{
    return (_text);
}

Button::stat_e Button::getStat(void) const
{
    return (_status);
}

void Button::update(const sf::RenderWindow &window)
{
    sf::Vector2f mousePosition = (sf::Vector2f)sf::Mouse::getPosition(window);
    bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    sf::Vector2f shapePosition = _shape.getPosition();
    sf::Vector2f shapeSize = _shape.getSize();

    if (_status == INACTIVE)
        return;
    if (mousePosition.x >= shapePosition.x && mousePosition.x <= shapePosition.x + shapeSize.x) {
        if (mousePosition.y >= shapePosition.y && mousePosition.y <= shapePosition.y + shapeSize.y) {
            _status = HOVER;
            if (isPressed) {
                _status = CLICK;
            }
        } else {
            _status = ACTIVE;
        }
    } else {
        _status = ACTIVE;
    }
}


void Button::setPosition(sf::Vector2f position)
{
    _shape.setPosition(position);
    switch (_textAlign)
    {
    case LEFT:
        _text.setPosition({position.x, position.y + (_shape.getSize().y - _text.getLocalBounds().height) / 2});
        break;
    case RIGHT:
        _text.setPosition({_shape.getPosition().x + _shape.getSize().x - _text.getLocalBounds().width, position.y + (_shape.getSize().y - _text.getLocalBounds().height) / 2});
        break;
    case CENTER:
        _text.setPosition({_shape.getPosition().x + _shape.getSize().x - _text.getLocalBounds().width - ((_shape.getSize().x - _text.getLocalBounds().width) / 2), position.y + (_shape.getSize().y - _text.getLocalBounds().height) / 2});
        break;
    default:
        break;
    }
}

sf::Vector2f Button::getPosition(void) const
{
    return (_shape.getPosition());
}

Button::~Button()
{
}