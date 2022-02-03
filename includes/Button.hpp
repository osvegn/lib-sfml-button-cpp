#pragma once

#include "IButton.hpp"
#include <SFML/Graphics.hpp>

class Button : public IButton {
    public:
        enum textAlign_e {
            RIGHT,
            LEFT,
            CENTER
        };
        enum stat_e {
            INACTIVE,
            ACTIVE,
            HOVER,
            CLICK
        };
        Button();
        Button(const Button &);
        Button(std::string fontPath);
        ~Button();
        Button &operator=(const Button &);
        void draw(sf::RenderWindow &window) const;
        void update(const sf::RenderWindow &window);
        sf::RectangleShape &getShape(void);
        sf::Text &getText(void);
        stat_e getStat(void) const;
        void setPosition(sf::Vector2f position);
        sf::Vector2f getPosition() const;
    protected:
        textAlign_e _textAlign;
        stat_e _status;
        sf::RectangleShape _shape;
        sf::Text _text;
        sf::Font _font;
};