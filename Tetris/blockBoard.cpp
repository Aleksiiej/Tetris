#include "BlockBoard.hpp"

BlockBoard::BlockBoard() noexcept
{
    for_each(begin(blockBoard_), end(blockBoard_), [](auto& el) { el.fill(Block()); });
    for (uint8_t i = 0; i < NUMBER_OF_COLUMNS; i++)
    {
        for (uint8_t j = 0; j < NUMBER_OF_ROWS; j++)
        {
            blockBoard_.at(i).at(j).block_.setPosition(static_cast<float>(i * GRID + GRID), static_cast<float>(j * GRID + GRID));
            blockBoard_.at(i).at(j).block_.setSize(Vector2f(GRID, GRID));
            blockBoard_.at(i).at(j).block_.setFillColor(Color::White);
        }
    }
}

BoardArray& BlockBoard::getBoardArrayRef() noexcept
{
    return blockBoard_;
}
