# include "Paddle.hpp"

Paddle::Paddle () {
    m_body.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));

    m_body.setOrigin(PADDLE_WIDTH/2, PADDLE_HEIGHT/2);
    m_body.setPosition(400.f, 550.f);
    m_body.setFillColor(sf::Color::Cyan);

    m_velocity = 0.f;
}

void Paddle::handleInput() {
    
};

void Paddle::update(float dt) {
    
};

void Paddle::draw(sf::RenderWindow &window) {
    window.draw(m_body);
};