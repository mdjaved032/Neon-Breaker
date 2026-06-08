# include "Paddle.hpp"

Paddle::Paddle (const Arena &arena) : m_arena(arena) {
    m_body.setSize(sf::Vector2f(Config::PADDLE_WIDTH, Config::PADDLE_HEIGHT));

    m_body.setOrigin(Config::PADDLE_WIDTH/2, Config::PADDLE_HEIGHT/2);
    m_body.setPosition(m_arena.getLeftWall().getPosition().x + Config::ARENA_WIDTH/2, m_arena.getFloor().getPosition().y - 30.f);
    m_body.setFillColor(sf::Color::Cyan);

    m_velocity = 0.f;
}

void Paddle::handleInput() {
    m_movingIntend = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) m_movingIntend -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) m_movingIntend += 1.f;
};

void Paddle::update(float dt) {
    m_velocity += m_movingIntend * Config::PADDLE_ACCEL * dt;
    m_velocity -= m_velocity * Config::PADDLE_FRICTION * dt;

    const auto& leftWall = m_arena.getLeftWall();
    const auto& rightWall = m_arena.getRightWall();
    
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

void Paddle::reset() {
    m_body.setPosition(m_arena.getLeftWall().getPosition().x + Config::ARENA_WIDTH/2, m_arena.getFloor().getPosition().y - 30.f);
    m_velocity = 0.f;
}