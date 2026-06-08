# pragma once

# include <SFML/Graphics.hpp>
# include "Config.hpp"

class Brick {
public:
    Brick(/* args */);
    // ~Brick();
    void draw(sf::RenderWindow &window);
    void setPosition(float x, float y);
    sf::Vector2f getSize();
    const sf::RectangleShape &getBrick() const { return m_body; }

private:
    sf::RectangleShape m_body;

};
