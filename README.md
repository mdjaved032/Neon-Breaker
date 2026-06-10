# Neon Breaker

Neon Breaker is a simple, classic arcade-style brick breaker game built using C++ and the SFML library. I created this project as a hands-on way to learn about 2D physics, game loops, and basic game architecture from scratch.

## 🚀 Key Features

*   **2D Collision Detection:** 
    *   Separated X and Y axis movement to handle corner collisions and stop the ball from getting stuck inside blocks.
    *   **Dynamic Ball Reflection:** Uses "hit factor" so the ball bounces at different angles depending on where it hits the paddle, allowing the player to aim the ball.
*   **Smooth Paddle Movement:** Uses basic acceleration and friction math to make the paddle slide smoothly instead of moving rigidly.
*   **Game States:** Manages different parts of the game (Serve, Play, Pause, Win, Game Over) using a state machine.
*   **Config System:** Centralizes all game constants and physics parameters into a single configuration file for easy balancing and tweaking.
*   **UI:** Simple text overlays using a classic arcade font.

## 🛠️ Tech Stack

*   **Language:** C++17
*   **Framework:** SFML (Graphics, Windowing)
*   **Build System:** CMake
*   **Platform:** Developed on Linux (Fedora), but **fully compatible with Windows and macOS**.

## 🎮 Controls

*   **Move Paddle:** `A` / `D` or `Left` / `Right` Arrow Keys
*   **Launch Ball:** `Space`
*   **Pause / Resume:** `Space`
*   **Restart Game:** `R`
*   **Exit:** `Esc`

## 📦 Installation & Build

### Prerequisites
*   A C++17 compatible compiler (GCC, Clang, or MSVC)
*   CMake (3.15+)
*   SFML 2.5 development libraries installed for your OS

### Build Instructions
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/mdjaved032/Neon-Breaker.git
    cd Neon-Breaker
    ```
2.  **Build the project:**
    ```bash
    mkdir build && cd build
    cmake ..
    
    # On Linux/macOS:
    make
    
    # Alternatively (Cross-platform):
    cmake --build .
    ```
3.  **Run the game:**
    *   **Linux/macOS:** `./Neon_Breaker`
    *   **Windows:** `.\Debug\Neon_Breaker.exe`

## 🏗️ Project Structure
*   `Game`: The main loop and state manager.
*   `Arena`: The walls and boundaries of the screen.
*   `Ball` & `Paddle`: The main moving parts with their own update logic.
*   `Config`: Settings and constants for the game.
