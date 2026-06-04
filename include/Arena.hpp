# pragma once

# include <SFML/Graphics.hpp>

class Arena {
public:
    Arena(/* args */);
    // ~Arena();
    void draw(sf::RenderWindow &window);
    const sf::RectangleShape &getRightWall() const { return m_rightWall; }
    const sf::RectangleShape &getLeftWall() const { return m_leftWall; }
    const sf::RectangleShape &getTopWall() const { return m_topWall; }
    const sf::RectangleShape &getFloor() const { return m_floor; }
private:
    sf::RectangleShape m_leftWall;
    sf::RectangleShape m_rightWall;
    sf::RectangleShape m_topWall;
    sf::RectangleShape m_floor;
};