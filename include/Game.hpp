# pragma once

# include <SFML/Graphics.hpp>
# include <vector>
# include "Paddle.hpp"
# include "Ball.hpp"
# include "Brick.hpp"
# include "Arena.hpp"

class Game {
public:
    Game(/* args */);
    // ~Game();
    void run();
    
private:
    void processEvents();
    void update(float dt);
    void render();
    void restart();
    void initBricks();

    sf::RenderWindow m_window;
    Paddle m_paddle;
    Ball m_ball;
    Arena m_arena;
    std::vector<Brick> m_bricks;

    sf::Clock m_clock;
};