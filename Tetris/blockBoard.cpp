#include <vector>

#include "BlockBoard.hpp"

BlockBoard::BlockBoard() noexcept
{
    for (uint8_t i = 0; i < NUMBER_OF_COLUMNS; i++)
    {
        for (uint8_t j = 0; j < NUMBER_OF_ROWS; j++)
        {
            blockBoard_.at(i).at(j).setPosition(static_cast<float>(i * GRID + GRID), static_cast<float>(j * GRID + GRID));
            blockBoard_.at(i).at(j).setSize(Vector2f(GRID, GRID));
            blockBoard_.at(i).at(j).setFillColor(Color::White);
        }
    }
}

const vector<uint8_t> BlockBoard::checkIfRowsFilled() const noexcept
{
    vector<uint8_t> filledRowsVec;
    uint8_t rowNumber{ NUMBER_OF_ROWS - 1 };
    uint8_t controlNumber = 0;
    for (int i = NUMBER_OF_ROWS - 1; i >= 0; i--)
    {
        for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
        {
            if (blockBoard_.at(j).at(i).getFillColor() == Color::Red)
            {
                controlNumber++;
            }
            if (controlNumber == 10)
            {
                filledRowsVec.push_back(rowNumber);
            }
        }
        rowNumber--;
        controlNumber = 0;
    }
    return filledRowsVec;
}

void BlockBoard::deleteRowOfBlocks(const vector<uint8_t>& vectorOfRows) noexcept
{
    for (const auto& el : vectorOfRows)
    {
        for (auto& column : blockBoard_)
        {
            column.at(el).setFillColor(Color::White);
            for (int i = el; i > 0; i--)
            {
                column.at(i).setFillColor(column.at(i - 1).getFillColor());
            }
        }

    }

}

BoardArray& BlockBoard::getBoardArrayRef() noexcept
{
    return blockBoard_;
}

void BlockBoard::setFillColor(const uint8_t& x, const uint8_t& y, const Color& color) noexcept
{
    blockBoard_.at(x).at(y).setFillColor(color);
}
