# pragma once

# include <SFML/Graphics.hpp>
# include <vector>
# include "Arena.hpp"
# include "Brick.hpp"
# include "Paddle.hpp"
# include "GameState.hpp"
# include "Config.hpp"

class Ball {
public:
    Ball(const Arena &arena);
    // ~Ball();
    void update(float dt, GameState &state, std::vector<Brick> &bricks, const Paddle &paddle);
    void draw(sf::RenderWindow &window);
    void setPosition(float x, float y) { m_body.setPosition(x, y); }
    const float getRadius() const { return Config::BALL_RADIUS; }

private:
    sf::CircleShape m_body;
    sf::Vector2f m_velocity;
    const Arena &m_arena;

};
