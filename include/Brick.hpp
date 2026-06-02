# pragma once

# include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(/* args */);
    // ~Brick();
    void draw(sf::RenderWindow &window);

private:
    sf::RectangleShape m_body;

    const float BRICK_WIDTH = 50.f;
    const float BRICK_HEIGHT = 50.f;
};
