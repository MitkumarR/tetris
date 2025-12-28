#include <cstdlib>
#include "Block.h"

Block::Block()
{
    CellSize = 30;
    RotationState = 0;
    ColorsVec = GetCellColors();
    RowOffset = 0;
    ColOffset = 0;
}

void Block::Draw()
{
    std::vector<Position> Tiles = GetCellPositions();

    for(Position items : Tiles)
    {
        DrawRectangle(items.Col * CellSize + 1, items.Row * CellSize + 1, CellSize - 1, CellSize - 1, ColorsVec[id]);   
    }
}

void Block::Move(int x, int y)
{
    RowOffset += x;
    ColOffset += y;
}

void Block::Rotate(int sign)
{
    if(abs(sign) == 1) RotationState = (RotationState + sign) % 4;

}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> Tiles = Cells[RotationState];
    std::vector<Position> MovedTiles;

    for(Position items: Tiles) MovedTiles.push_back({items.Row + RowOffset, items.Col + ColOffset});
        
    return MovedTiles;
}