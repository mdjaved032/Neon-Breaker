# pragma once

# include <SFML/Graphics.hpp>

class Arena {
public:
    Arena(/* args */);
    // ~Arena();
    void draw(sf::RenderWindow &window);
private:
    sf::RectangleShape m_leftWall;
    sf::RectangleShape m_rightWall;
    sf::RectangleShape m_topWall;
    sf::RectangleShape m_floor;
};