# pragma once

namespace Config {
    // Window Settings
    inline constexpr float SCREEN_WIDTH = 800.f;
    inline constexpr float SCREEN_HEIGHT = 600.f;
    inline constexpr size_t SCREEN_FRAME_RATE = 60;

    // Arena Settings
    inline constexpr float ARENA_WIDTH = 800.f;
    inline constexpr float ARENA_HEIGHT = 600.f;
    inline constexpr float ARENA_WALL_THICKNESS = 1.f;

    // Paddle Settings
    inline constexpr float PADDLE_WIDTH = 100.f;
    inline constexpr float PADDLE_HEIGHT = 6.f;
    inline constexpr float PADDLE_ACCEL = 6000.f;
    inline constexpr float PADDLE_FRICTION = 10.f;

    // Brick Settings
    inline constexpr float BRICK_WIDTH = 50.f;
    inline constexpr float BRICK_HEIGHT = 20.f;

    // Ball Settings
    inline constexpr float BALL_RADIUS = 6.f;
    inline constexpr float VERTICAL_SPEED = 400.f;
    inline constexpr float HORIZONTAL_MAX_SPEED = 500.f;
}