# include "Paddle.hpp"

Paddle::Paddle () {
    m_body.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));

    m_body.setOrigin(PADDLE_WIDTH/2, PADDLE_HEIGHT/2);
    m_body.setPosition(400.f, 550.f);
    m_body.setFillColor(sf::Color::Cyan);

    m_velocity = 0.f;
}

void Paddle::handleInput() {
    m_movingIntend = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) m_movingIntend -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) m_movingIntend += 1.f;
};

void Paddle::update(float dt, Arena &arena) {
    m_velocity += m_movingIntend * PADDLE_ACCEL * dt;
    m_velocity -= m_velocity * PADDLE_FRICTION * dt;

    const auto& leftWall = arena.getLeftWall();
    const auto& rightWall = arena.getRightWall();
    
    m_body.move(m_velocity * dt, 0.f);
    if (m_body.getGlobalBounds().intersects(leftWall.getGlobalBounds())) {
        m_body.setPosition(leftWall.getPosition().x + leftWall.getSize().x + m_body.getSize().x/2, m_body.getPosition().y);
    }
    if (m_body.getGlobalBounds().intersects(rightWall.getGlobalBounds())) {
        m_body.setPosition(rightWall.getPosition().x - m_body.getSize().x/2, m_body.getPosition().y);
    }
};

void Paddle::draw(sf::RenderWindow &window) {
    window.draw(m_body);
};