#!/bin/bash
# Exit immediately if a command exits with a non-zero status
set -e

echo "Building Tetris..."
mkdir -p build
cd build
cmake ..
cmake --build .

echo "Starting Tetris..."
if [ -f "./Tetris" ]; then
    ./Tetris
elif [ -f "./Debug/Tetris" ]; then
    ./Debug/Tetris
else
    echo "Error: Could not find Tetris executable."
    exit 1
fi
cd ..
