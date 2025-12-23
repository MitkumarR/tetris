@echo off
echo Building Tetris...
if not exist build mkdir build
cd build
cmake ..
if %ERRORLEVEL% NEQ 0 (
    echo CMake configuration failed.
    exit /b 1
)
cmake --build . --config Debug
if %ERRORLEVEL% NEQ 0 (
    echo Build failed.
    exit /b 1
)

echo Starting Tetris...
rem Try to find the executable in likely locations (Multi-configuration vs Single-configuration generators)
if exist "Debug\Tetris.exe" (
    ".\Debug\Tetris.exe"
) else if exist "Tetris.exe" (
    ".\Tetris.exe"
) else (
    echo Error: Could not find Tetris.exe executable.
)
cd ..