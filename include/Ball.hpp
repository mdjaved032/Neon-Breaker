# pragma once

# include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(/* args */);
    // ~Ball();
    void update(float dt);
    void draw(sf::RenderWindow &window);

private:
    sf::CircleShape m_body;
    sf::Vector2f m_velocity;

    const float BALL_RADIUS = 10.f;
};
