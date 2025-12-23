#pragma once
#include <vector>
#include <raylib.h>

/*
	0   : empty cell
	1-7 : colored cell
*/

class Grid
{
	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> Colors;

public:
	int Matrix[20][10];

	Grid();

	void Initialize();
	void Draw();
};