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

    static constexpr float PADDLE_ACCEL = 6000.f;
    static constexpr float PADDLE_FRICTION = 10.f;
    static constexpr float PADDLE_WIDTH = 100.f;
    static constexpr float PADDLE_HEIGHT = 6.f;
};