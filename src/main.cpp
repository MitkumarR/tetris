#include <raylib.h>
#include "Game.h"
#include <ctime>
#include <cstdlib>

const int ROWS = 20;
const int COLS = 10;

double LastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double CurrentTime = GetTime();
	if(CurrentTime - LastUpdateTime >= interval)
	{
		LastUpdateTime = CurrentTime;
		return true;
	}

	return false;
}
int main()
{
	srand(time(0));
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Game Tetris = Game();
	while (!WindowShouldClose())
	{
		Tetris.HandleInput();
		if(EventTriggered(0.5)) Tetris.MoveBlockDown();
		BeginDrawing();
		ClearBackground(WHITE);
		
		Tetris.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
} 