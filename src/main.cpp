#include <raylib.h>
#include "Grid.h"

const int ROWS = 20;
const int COLS = 10;

int main()
{
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Grid grid = Grid();
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("Hello, Raylib!", 350, 280, 20, DARKGRAY);
		grid.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
} 