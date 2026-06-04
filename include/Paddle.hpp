# pragma once

# include <SFML/Graphics.hpp>
# include "Arena.hpp"

class Paddle {
public:
    Paddle(/* args */);
    // ~Paddle();
    void handleInput();
    void update(float dt, Arena &arena);
    void draw(sf::RenderWindow &window);
    const sf::RectangleShape &getPaddle() const { return m_body; }

private:
    sf::RectangleShape m_body;
    float m_movingIntend;
    float m_velocity;

    const float PADDLE_ACCEL = 3000.f;
    const float PADDLE_FRICTION = 5.f;
    const float PADDLE_WIDTH = 100.f;
    const float PADDLE_HEIGHT = 10.f;
};