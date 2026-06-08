# pragma once

# include <SFML/Graphics.hpp>
# include "Arena.hpp"
# include "Config.hpp"

class Paddle {
public:
    Paddle(const Arena &arena);
    // ~Paddle();
    void handleInput();
    void update(float dt);
    void draw(sf::RenderWindow &window);
    void reset();
    const sf::RectangleShape &getPaddle() const { return m_body; }

private:
    sf::RectangleShape m_body;
    float m_movingIntend;
    float m_velocity;
    const Arena &m_arena;
};