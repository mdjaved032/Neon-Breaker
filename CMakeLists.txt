set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.15)
project(Neon_Breaker VERSION 1.0 LANGUAGES CXX)

# Force the standard to C++17 or C++20 for clean modern C++ development
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Look for SFML on Fedora (we need window, graphics, system for collision work)
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system audio)

# 2. Grab all the .cpp source files inside your src/ directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 3. Create the executable name
add_executable(${PROJECT_NAME} ${SOURCES})

# 4. Point CMake to your include/ directory for header (.hpp) files
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 5. Link the SFML libraries to your executable
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# 6. Crucial for games: This automatically copies your 'assets' folder 
# into the 'build' directory every time you compile so your game can find textures/fonts.
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
)