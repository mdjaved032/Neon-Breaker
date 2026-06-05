# pragma once

# include <SFML/Graphics.hpp>

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

    static constexpr float BRICK_WIDTH = 50.f;
    static constexpr float BRICK_HEIGHT = 20.f;
};
