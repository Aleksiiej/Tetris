#include "BlockBoard.hpp"

BlockBoard::BlockBoard() noexcept
{
    for (uint8_t i = 0; i < NUMBER_OF_COLUMNS; i++)
    {
        for (uint8_t j = 0; j < NUMBER_OF_ROWS; j++)
        {
            blockBoard_.at(i).at(j).getBlockRef().setPosition(static_cast<float>(i * GRID + GRID), static_cast<float>(j * GRID + GRID));
            blockBoard_.at(i).at(j).getBlockRef().setSize(Vector2f(GRID, GRID));
            blockBoard_.at(i).at(j).getBlockRef().setFillColor(Color::White);
        }
    }
}

BoardArray& BlockBoard::getBoardArrayRef() noexcept
{
    return blockBoard_;
}

void BlockBoard::setFillColor(const uint8_t& x, const uint8_t& y, const Color& color) noexcept
{
    blockBoard_.at(x).at(y).getBlockRef().setFillColor(color);
}
