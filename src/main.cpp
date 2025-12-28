#include <raylib.h>
#include "Game.h"
#include <ctime>
#include <cstdlib>

const int ROWS = 20;
const int COLS = 10;

int main()
{
	srand(time(0));
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Game Tetris = Game();
	while (!WindowShouldClose())
	{
		Tetris.HandleInput();
		BeginDrawing();
		ClearBackground(WHITE);
		
		Tetris.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
} 