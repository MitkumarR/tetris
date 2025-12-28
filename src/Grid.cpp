#include "Grid.h"
#include "Colors.h"

Grid::Grid()
{
    NumRows = 20;
    NumCols = 10;
    CellSize = 30;

    Initialize();
    Colors = GetCellColors();
}

void Grid::Initialize()
{
    for(int i = 0; i < NumRows; i++)
        for(int j = 0; j < NumCols; j++)
            Matrix[i][j] = 0;
}


void Grid::Draw()
{
    for(int i = 0; i < NumRows; i++)
    {
        for(int j = 0; j < NumCols; j++)
        {
             int CellValue = Matrix[i][j];
             DrawRectangle(j * CellSize + 1, i * CellSize+1, CellSize-1, CellSize-1, Colors[CellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int col   )
{
    if(row >= 0 && row < NumRows && col >= 0 && col < NumCols) return false;
    return true; 
}