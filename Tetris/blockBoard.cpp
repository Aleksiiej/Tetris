#include "BlockBoard.hpp"

BlockBoard::BlockBoard()
{
    for_each(begin(blockBoard_), end(blockBoard_), [](auto& el) { el.fill(Block()); });
    for (int i = 0; i <= NUMBER_OF_COLUMNS; i++)
    {
        for (int j = 0; j <= NUMBER_OF_ROWS; j++)
        {
            blockBoard_.at(i).at(j).block_.setPosition(i * GRID, j * GRID);
            blockBoard_.at(i).at(j).block_.setSize(Vector2f(GRID, GRID));
            blockBoard_.at(i).at(j).block_.setFillColor(Color::Green); //TODO: change color to White as in background
        }
    }
}
