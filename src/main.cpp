#include <raylib.h>
#include "Grid.h"
#include "Blocks.cpp"

const int ROWS = 20;
const int COLS = 10;

int main()
{
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Grid grid = Grid();
	
	ZBlock block = ZBlock();
	block.Move(4, 3);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("Hello, Raylib!", 350, 280, 20, DARKGRAY);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
} 