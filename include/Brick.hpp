# pragma once

# include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(/* args */);
    // ~Brick();
    void draw(sf::RenderWindow &window);
    void setPosition(float x, float y);
    sf::Vector2f getSize();

private:
    sf::RectangleShape m_body;

    const float BRICK_WIDTH = 50.f;
    const float BRICK_HEIGHT = 20.f;
};
