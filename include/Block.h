#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{

    int CellSize;
    int RotationState;
    std::vector<Color> ColorsVec;
    int RowOffset;
    int ColOffset;
    
public:
    int id;

    Block();
    std::map<int, std::vector<Position>> Cells;
    std::vector<Position> GetCellPositions();  
    void Draw();
    void Move(int x, int y);
    void Rotate(int sign);
};