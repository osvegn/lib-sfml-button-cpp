#pragma once

#include "IButton.hpp"
#include <SFML/Graphics.hpp>

class Button : public IButton {
    public:
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
        sf::RectangleShape &getShape(void);
        sf::Text &getText(void);
        stat_e getStat(void) const;
    protected:
        stat_e _status;
        sf::RectangleShape _shape;
        sf::Text _text;
        sf::Font _font;
};