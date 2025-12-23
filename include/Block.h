#pragma once
#include <vector>
#include <map>
#include "Position.h"

class Block
{

    int CellSize;
    int RotationState;
    
public:
    Block();
    int id;
    std::map<int, std::vector<Position>> Cells;
}