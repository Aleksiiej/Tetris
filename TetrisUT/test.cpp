#include "pch.h"
#include "../../Tetris/Tetris/BlockBoard.hpp"
#include "../../Tetris/GlobalValues.hpp"

#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

using namespace std;
using namespace sf;

class BlockBoardFixture : public ::testing::Test
{
public:
    void SetUp()
    {
        for (uint8_t i = 0; i < NUMBER_OF_COLUMNS; i++)
        {
            for (uint8_t j = 0; j < NUMBER_OF_ROWS; j++)
            {
                testBlockBoard_.getBoardArrayRef().at(i).at(j).setPosition(static_cast<float>(i * GRID + GRID), static_cast<float>(j * GRID + GRID));
                testBlockBoard_.getBoardArrayRef().at(i).at(j).setSize(Vector2f(GRID, GRID));
                testBlockBoard_.getBoardArrayRef().at(i).at(j).setFillColor(Color::White);
            }
        }
    }
protected:
    BlockBoard testBlockBoard_;
};

TEST_F(BlockBoardFixture, checkWhichRowsFilled)
{
    for (uint8_t i = 0; i < NUMBER_OF_COLUMNS; i++)
    {
        testBlockBoard_.getBoardArrayRef().at(i).at(19).setFillColor(Color::Red);
        testBlockBoard_.getBoardArrayRef().at(i).at(10).setFillColor(Color::Red);
    }

    auto resultVec = testBlockBoard_.checkWhichRowsFilled();

    EXPECT_EQ(resultVec.at(0), 10);
    EXPECT_EQ(resultVec.at(1), 19);
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}