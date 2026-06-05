# pragma once

# include <SFML/Graphics.hpp>
# include <vector>
# include "Arena.hpp"
# include "Brick.hpp"
# include "Paddle.hpp"

class Ball {
public:
    Ball(/* args */);
    // ~Ball();
    void update(float dt, std::vector<Brick> &bricks, const Paddle &paddle, const Arena &arena);
    void draw(sf::RenderWindow &window);

private:
    sf::CircleShape m_body;
    sf::Vector2f m_velocity;

    static constexpr float BALL_RADIUS = 6.f;
    static constexpr float VERTICAL_SPEED = 400.f;
    static constexpr float HORIZONTAL_MAX_SPEED = 500.f;
};
