# include "Arena.hpp"

Arena::Arena() {
    float width = 1.f;

    m_leftWall.setSize({width, 600.f});
    m_leftWall.setFillColor(sf::Color::Green);

    m_rightWall.setSize({width, 600.f});
    m_rightWall.setPosition({800.f - width, 0.f});
    m_rightWall.setFillColor(sf::Color::Green);


    m_topWall.setSize({800.f, width});
    m_topWall.setFillColor(sf::Color::Green);


    m_floor.setSize({800.f, width});
    m_floor.setPosition({0, 600.f - width});
    m_floor.setFillColor(sf::Color::Red);
}

void Arena::draw(sf::RenderWindow &window) {
    window.draw(m_floor);
    window.draw(m_leftWall);
    window.draw(m_rightWall);
    window.draw(m_topWall);
}