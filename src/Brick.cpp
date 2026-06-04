# include "Brick.hpp"

Brick::Brick () {
    m_body.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
    m_body.setFillColor(sf::Color::Transparent);
    m_body.setOutlineThickness(-1.f);
    m_body.setOutlineColor(sf::Color::Magenta);
}

void Brick::draw(sf::RenderWindow &window) {
    window.draw(m_body);
}

void Brick::setPosition(float x, float y) {
    m_body.setPosition(x, y);
}

sf::Vector2f Brick::getSize() {
    return {BRICK_WIDTH, BRICK_HEIGHT};
}