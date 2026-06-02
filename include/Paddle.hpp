# pragma once

# include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(/* args */);
    // ~Paddle();
    void handleInput();
    void update(float dt);
    void draw(sf::RenderWindow &window);

private:
    sf::RectangleShape m_body;
    float m_velocity;

    const float PADDLE_SPEED = 500.f;
    const float PADDLE_WIDTH = 100.f;
    const float PADDLE_HEIGHT = 10.f;
};