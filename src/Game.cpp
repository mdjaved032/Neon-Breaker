# include "Game.hpp"

Game::Game() : m_window(sf::VideoMode(800.f, 600.f), "Neon Breaker") {
    m_window.setFramerateLimit(60);

    const int ROW = 5;
    const int COL = 15;
    const int GAP = 2;

    Brick b;
    int colSpacing = (800 - (COL * b.getSize().x) - ((COL-1) * GAP))/2;
    int topSpacing = 20;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            Brick brick;
            float x = colSpacing + j * (brick.getSize().x + GAP);
            float y = topSpacing + i * (brick.getSize().y + GAP);
            brick.setPosition(x, y);
            m_bricks.push_back(brick);
        }
    }
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            m_window.close();
        }
    }
}

void Game::update(float dt) {
    m_paddle.handleInput();
    m_paddle.update(dt, m_arena);
    m_ball.update(dt);
}

void Game::render() {
    m_window.clear();
    for (auto &brick: m_bricks) {
        brick.draw(m_window);
    }
    m_paddle.draw(m_window);
    m_ball.draw(m_window);
    m_arena.draw(m_window);
    m_window.display();
}