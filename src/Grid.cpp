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

bool Grid::IsCellEmpty(int row, int col)
{
    if(Matrix[row][col] == 0) return true;
    return false;
}

bool Grid::IsRowCompleted(int row)
{
    for(int i = 0; i < NumCols; i++)
        if(Matrix[row][i] == 0) return false;
    
    return true;
}

void Grid::RemoveRow(int row)
{
    for(int i = 0; i < NumCols; i++)
        Matrix[row][i] = 0; 
}

void Grid::MoveRowDown(int row, int count)
{
    for(int i = 0; i < NumCols; i++)
        Matrix[row + count][i] = Matrix[row][i];
}

int Grid::RemoveAllRows()
{
    int RowRemoved = 0;
    for(int i = NumRows - 1; i >= 0; i--)
    {
        if(IsRowCompleted(i))
        {
            RemoveRow(i);
            RowRemoved++;
        }
        else if (RowRemoved > 0)
        {
            MoveRowDown(i, RowRemoved);
        }
    }
    
    return RowRemoved;
}