# include "Game.hpp"

Game::Game() 
    : m_window(sf::VideoMode(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT), "Neon Breaker"),
      m_paddle(m_arena),
      m_ball(m_arena)
{
    m_window.setFramerateLimit(Config::SCREEN_FRAME_RATE);

    initBricks();
    m_state = GameState::Serve;

    if (!m_font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf")) {

    }
    m_messageText.setFont(m_font);
    m_messageText.setCharacterSize(30);
    m_messageText.setFillColor(sf::Color::White);
}

void Game::run () {
    while(m_window.isOpen()) {
        float dt = m_clock.restart().asSeconds();

        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) m_window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) restart();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                if (m_state == GameState::Play) {
                    m_state = GameState::Pause;
                } else if (m_state == GameState::GameOver) {
                    restart();
                } else {
                    m_state = GameState::Play;
                }
            }
        }
    }
}

void Game::update(float dt) {
    switch (m_state) {
        case GameState::Serve: {
            m_paddle.handleInput();
            m_paddle.update(dt);
            
            const auto& paddle = m_paddle.getPaddle();
            m_ball.setPosition(
                paddle.getPosition().x,
                paddle.getPosition().y - paddle.getSize().y/2 - m_ball.getRadius()
            );
            break;
        }
        case GameState::Play: {
            m_paddle.handleInput();
            m_paddle.update(dt);
            m_ball.update(dt, m_state, m_bricks, m_paddle);

            if (m_bricks.empty()) m_state = GameState::Win;
            break;
        }
        case GameState::Pause: {
            m_messageText.setString("PAUSED");
            sf::FloatRect textBounds = m_messageText.getLocalBounds();
            m_messageText.setOrigin(textBounds.left + textBounds.width/2, textBounds.top + textBounds.height/2);
            m_messageText.setPosition(m_arena.getLeftWall().getPosition().x + Config::ARENA_WIDTH/2,m_arena.getRightWall().getPosition().y + Config::ARENA_HEIGHT/2);
            break;
        }
        case GameState::GameOver: {
            m_messageText.setString("GAME OVER");
            sf::FloatRect textBounds = m_messageText.getLocalBounds();
            m_messageText.setOrigin(textBounds.left + textBounds.width/2, textBounds.top + textBounds.height/2);
            m_messageText.setPosition(m_arena.getLeftWall().getPosition().x + Config::ARENA_WIDTH/2,m_arena.getRightWall().getPosition().y + Config::ARENA_HEIGHT/2);
            break;
        }
        case GameState::Win: {
            m_messageText.setString("YOU WIN!");
            sf::FloatRect textBounds = m_messageText.getLocalBounds();
            m_messageText.setOrigin(textBounds.left + textBounds.width/2, textBounds.top + textBounds.height/2);
            m_messageText.setPosition(m_arena.getLeftWall().getPosition().x + Config::ARENA_WIDTH/2,m_arena.getRightWall().getPosition().y + Config::ARENA_HEIGHT/2);
            break;
        }
    }
}

void Game::render() {
    m_window.clear();
    for (auto &brick: m_bricks) {
        brick.draw(m_window);
    }
    m_paddle.draw(m_window);
    m_ball.draw(m_window);
    m_arena.draw(m_window);

    if (m_state != GameState::Play && m_state != GameState::Serve) {
        m_window.draw(m_messageText);
    }
    m_window.display();
}

void Game::restart() {
    initBricks();
    m_paddle.reset();
    m_state = GameState::Serve;
}

void Game::initBricks() {
    m_bricks.clear();
    const int ROW = 5;
    const int COL = 15;
    const int GAP = 2;

    int colSpacing = (Config::ARENA_WIDTH - (COL * Config::BRICK_WIDTH) - ((COL-1) * GAP))/2;
    int topSpacing = 20;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            Brick brick;
            float x = m_arena.getLeftWall().getPosition().x + colSpacing + j * (brick.getSize().x + GAP);
            float y = m_arena.getTopWall().getPosition().y + topSpacing + i * (brick.getSize().y + GAP);
            brick.setPosition(x, y);
            m_bricks.push_back(brick);
        }
    }
}