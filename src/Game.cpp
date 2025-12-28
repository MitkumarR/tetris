#include <random>
#include "Blocks.cpp"
#include "Game.h"

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    CurrentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if(blocks.empty()) blocks = GetAllBlocks();

    int RandomIndex = rand() % blocks.size();
    Block block = blocks[RandomIndex];
    blocks.erase(blocks.begin() + RandomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    CurrentBlock.Draw();
}

void Game::HandleInput()
{
    int KeyPressed = GetKeyPressed();

    switch(KeyPressed)
    {
        case KEY_LEFT: 
            CurrentBlock.Move(0, -1); 
            if(IsBlockOutside() || BlockFits() == false) CurrentBlock.Move(0, 1); 
            break;

        case KEY_RIGHT: 
            CurrentBlock.Move(0, 1);
            if(IsBlockOutside() || BlockFits() == false) CurrentBlock.Move(0, -1); 
            break;

        case KEY_DOWN: 
            CurrentBlock.Move(1, 0);
            if(IsBlockOutside() || BlockFits() == false) CurrentBlock.Move(-1, 0); 
            break;
        
        case KEY_UP:
            CurrentBlock.Rotate(1);
            if(IsBlockOutside() || BlockFits() == false) CurrentBlock.Rotate(-1);
            break;
    }
}

void Game::MoveBlockDown()
{
    CurrentBlock.Move(1, 0);
    if(IsBlockOutside() || BlockFits() == false) 
    {
        CurrentBlock.Move(-1, 0);
        LockBlock();
    }
}

void Game::LockBlock()
{
    std::vector<Position> Tiles = CurrentBlock.GetCellPositions();
    for(Position items : Tiles)
        grid.Matrix[items.Row][items.Col] = CurrentBlock.id;

    CurrentBlock = NextBlock;
    NextBlock = GetRandomBlock();
    grid.RemoveAllRows();
}
bool Game::IsBlockOutside()
{
    std::vector<Position> Tiles = CurrentBlock.GetCellPositions();
    for(Position items : Tiles)
        if(grid.IsCellOutside(items.Row, items.Col)) return true;
    
    return false;
}

bool Game::BlockFits()
{
    std::vector<Position> Tiles = CurrentBlock.GetCellPositions();
    for(Position items : Tiles)
        if(grid.IsCellEmpty(items.Row, items.Col) == false) return false;
    
    return true;
}
