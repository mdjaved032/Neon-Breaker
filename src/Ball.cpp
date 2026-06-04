# include "Ball.hpp"

Ball::Ball () {
    m_body.setRadius(BALL_RADIUS);
    m_body.setOrigin(BALL_RADIUS, BALL_RADIUS);
    m_body.setPosition(400.f, 300.f);
    m_body.setFillColor(sf::Color::White);

}

void Ball::update(float dt) {
    
}

void Ball::draw(sf::RenderWindow &window) {
    window.draw(m_body);
}