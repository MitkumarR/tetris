#pragma once
#include "Grid.h"
#include "Block.h"

class Game
{
    std::vector<Block> blocks;

public:
    Game();
    Grid grid;
    Block NextBlock;
    Block CurrentBlock;
    
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    bool IsBlockOutside();
};
