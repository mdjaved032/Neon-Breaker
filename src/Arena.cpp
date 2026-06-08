# include "Arena.hpp"

Arena::Arena() {
    m_leftWall.setSize({Config::ARENA_WALL_THICKNESS, Config::ARENA_HEIGHT});
    m_leftWall.setFillColor(sf::Color::Green);

    m_rightWall.setSize({Config::ARENA_WALL_THICKNESS, Config::ARENA_HEIGHT});
    m_rightWall.setPosition({Config::ARENA_WIDTH - Config::ARENA_WALL_THICKNESS, 0.f});
    m_rightWall.setFillColor(sf::Color::Green);


    m_topWall.setSize({Config::ARENA_WIDTH, Config::ARENA_WALL_THICKNESS});
    m_topWall.setFillColor(sf::Color::Green);


    m_floor.setSize({Config::ARENA_WIDTH, Config::ARENA_WALL_THICKNESS});
    m_floor.setPosition({0, Config::ARENA_HEIGHT - Config::ARENA_WALL_THICKNESS});
    m_floor.setFillColor(sf::Color::Red);
}

void Arena::draw(sf::RenderWindow &window) {
    window.draw(m_floor);
    window.draw(m_leftWall);
    window.draw(m_rightWall);
    window.draw(m_topWall);
}