cmake_minimum_required(VERSION 3.11)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

# Define sources
set(SOURCES
    src/main.cpp
    src/Grid.cpp
    src/Colors.cpp
    src/Position.cpp
    src/Block.cpp
    src/Game.cpp
)

# Add include directories
include_directories(include)

# -----------------------------------------------------------------------------------------
# Platform Independent Raylib Setup
# -----------------------------------------------------------------------------------------
# We use FetchContent to automatically download and build raylib if needed.
# This ensures the project runs on Windows, Linux, and macOS without manual installation.
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

# -----------------------------------------------------------------------------------------
# Build Executable
# -----------------------------------------------------------------------------------------
# Build Executable
# -----------------------------------------------------------------------------------------
add_executable(Tetris ${SOURCES})

# Link Raylib
target_link_libraries(Tetris PRIVATE raylib)

# Platform specific linking (mostly handled by raylib target, but being explicit just in case)
if (WIN32)
    target_link_libraries(Tetris PRIVATE opengl32 gdi32 winmm)
endif()

# Copy resources if you had any (example)
# file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})
