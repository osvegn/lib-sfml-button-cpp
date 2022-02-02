#pragma once

#include "IButton.hpp"
#include <SFML/Graphics.hpp>

class Button : public IButton {
    public:
        Button();
        Button(const Button &);
        ~Button();
        Button &operator=(const Button &);
        void draw(sf::RenderWindow &window) const;
    protected:
        enum stat_e {
            INACTIVE,
            ACTIVE,
            HOVER,
            CLICK
        };
        stat_e _status;
        sf::RectangleShape _shape;
};