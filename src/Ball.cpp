# include "Ball.hpp"

Ball::Ball () {
    m_body.setRadius(BALL_RADIUS);
    m_body.setOrigin(BALL_RADIUS, BALL_RADIUS);
    m_body.setPosition(400.f, 300.f);
    m_body.setFillColor(sf::Color::White);
    
    m_velocity = sf::Vector2f(0.f, VERTICAL_SPEED);
}

void Ball::update(float dt, GameState &state, std::vector<Brick> &bricks, const Paddle &paddle, const Arena &arena) {
    const auto &game_paddle = paddle.getPaddle();
    const auto &rightWall = arena.getRightWall();
    const auto &leftWall = arena.getLeftWall();
    const auto &TopWall = arena.getTopWall();
    const auto &floor = arena.getFloor();

    m_body.move(m_velocity.x * dt, 0.f);
    // Brick collision X-direction
    for (size_t i = 0; i < bricks.size(); ++i) {
        const auto& curr_brick = bricks[i].getBrick();
        if (m_body.getGlobalBounds().intersects(curr_brick.getGlobalBounds())) {
            if (m_velocity.x > 0) {
                m_body.setPosition({curr_brick.getPosition().x - BALL_RADIUS, m_body.getPosition().y});
            } else {
                m_body.setPosition({curr_brick.getPosition().x + curr_brick.getSize().x + BALL_RADIUS, m_body.getPosition().y});
            }
            m_velocity.x *= -1.f;
            bricks.erase(bricks.begin() + i);
            break;
        }
    }

    // Paddle collision X-direction
    if (m_body.getGlobalBounds().intersects(game_paddle.getGlobalBounds())) {
        float ballBottom = m_body.getPosition().y + BALL_RADIUS;
        float paddleTop = game_paddle.getPosition().y - game_paddle.getSize().y/2;
        if (ballBottom > paddleTop + 2.f) {
            if (m_body.getPosition().x < game_paddle.getPosition().x) {
                m_body.setPosition({game_paddle.getPosition().x - game_paddle.getSize().x/2 - BALL_RADIUS, m_body.getPosition().y});
            } else {
                m_body.setPosition({game_paddle.getPosition().x + game_paddle.getSize().x/2 + BALL_RADIUS, m_body.getPosition().y});
            }    
            m_velocity.x *= -1.f;
        }
    }

    m_body.move(0.f, m_velocity.y * dt);
    // Brick collision Y-direction
    for (size_t i = 0; i < bricks.size(); ++i) {
        const auto& curr_brick = bricks[i].getBrick();
        if (m_body.getGlobalBounds().intersects(curr_brick.getGlobalBounds())) {
            if (m_velocity.y > 0) {
                m_body.setPosition({m_body.getPosition().x, curr_brick.getPosition().y - BALL_RADIUS});
            } else {
                m_body.setPosition({m_body.getPosition().x, curr_brick.getPosition().y + curr_brick.getSize().y + BALL_RADIUS});
            }
            m_velocity.y *= -1.f;
            bricks.erase(bricks.begin() + i);
            break;
        }
    }

    // Paddle collision Y-direction
    if (m_body.getGlobalBounds().intersects(game_paddle.getGlobalBounds())) {
        float hitFactor = (m_body.getPosition().x - game_paddle.getPosition().x) / (game_paddle.getSize().x/2);

        m_body.setPosition({m_body.getPosition().x, game_paddle.getPosition().y - game_paddle.getSize().y/2 - BALL_RADIUS});

        m_velocity.x = HORIZONTAL_MAX_SPEED * hitFactor;
        m_velocity.y = -std::abs(m_velocity.y);
    }

    { /* Arena Wall Collision */
        if (m_body.getGlobalBounds().intersects(leftWall.getGlobalBounds())) {
            m_body.setPosition({leftWall.getPosition().x + leftWall.getSize().x + BALL_RADIUS, m_body.getPosition().y});
            m_velocity.x *= -1.f;
        }
        if (m_body.getGlobalBounds().intersects(rightWall.getGlobalBounds())) {
            m_body.setPosition({rightWall.getPosition().x - BALL_RADIUS, m_body.getPosition().y});
            m_velocity.x *= -1.f;
        }
        if (m_body.getGlobalBounds().intersects(TopWall.getGlobalBounds())) {
            m_body.setPosition({m_body.getPosition().x, TopWall.getPosition().y + TopWall.getSize().y + BALL_RADIUS});
            m_velocity.y *= -1.f;
        }
        if (m_body.getGlobalBounds().intersects(floor.getGlobalBounds())) {
            m_body.setPosition({m_body.getPosition().x, floor.getPosition().y - floor.getSize().y - BALL_RADIUS});
            m_velocity = sf::Vector2f(0.f, 0.f);
            state = GameState::GameOver;
        }
    }

}

void Ball::draw(sf::RenderWindow &window) {
    window.draw(m_body);
}