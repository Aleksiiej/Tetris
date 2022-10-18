#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Band.hpp"
#include "BlockBoard.hpp"
#include "BlockCreator.hpp"
#include "Block1.hpp"
#include "Block2.hpp"
#include "EndgameText.hpp"
#include "GlobalValues.hpp"

using namespace sf;
using namespace std;

void drawBoard(const Band& band, const shared_ptr<BlockBoard>& blockBoardPtr, RenderWindow& window) noexcept;

int main()
{
    RenderWindow window{ VideoMode{800, 600}, "Tetris" };
    window.setFramerateLimit(60);
    Event event;

    GameStatus gameStatus{GameStatus::Ongoing};
    const Band band{ GRID, GRID };
    const EndgameText endgameText;
    const auto blockBoardPtr = make_shared<BlockBoard>();
    BlockCreator blockCreator(blockBoardPtr);
    auto ptrToBlock = move(blockCreator.createRandomBlock());

    while (true)
    {
        window.clear(Color::White);
        if (!ptrToBlock->checkIfLost())
        {
            gameStatus = GameStatus::Lost;
        }
        if (gameStatus == GameStatus::Ongoing)
        {
            while (window.pollEvent(event))
            {
                if (event.type == Event::EventType::Closed)
                {
                    window.close();
                    break;
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Right)
                {
                    ptrToBlock->moveRight();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Left)
                {
                    ptrToBlock->moveLeft();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Down)
                {
                    ptrToBlock->moveDown();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Space)
                {
                    ptrToBlock->rotate();
                }
            }
        }
        else
        {
            drawBoard(band, blockBoardPtr, window);
            window.draw(endgameText);
            window.display();
            sleep(milliseconds(2000));
            window.close();
            return 0;
        }
        blockBoardPtr->handleFilledRows();
        drawBoard(band, blockBoardPtr, window);
        for (const auto& block : ptrToBlock->getBlock1ArrayRef())
        {
            window.draw(block);
        }
        window.display();
        sleep(milliseconds(GAME_SPEED));
        if (ptrToBlock->isFallingPossible())
        {
            ptrToBlock->fall();
        }
        else
        {
            ptrToBlock.reset(nullptr);
            ptrToBlock = move(blockCreator.createRandomBlock());
        }
    }
    return 0;
}

void drawBoard(const Band& band, const shared_ptr<BlockBoard>& blockBoardPtr, RenderWindow& window) noexcept
{
    window.draw(band);

    RectangleShape singleField; // TODO: figure out how to use smaller class than RectangleShape
    singleField.setSize(Vector2f{ GRID, GRID });
    for (uint8_t i = 0; i < NUMBER_OF_COLUMNS; i++)
    {
        for (uint8_t j = 0; j < NUMBER_OF_ROWS; j++)
        {
            singleField.setFillColor(blockBoardPtr->getBoardArrayRef().at(i).at(j));
            singleField.setPosition(static_cast<float>(i * GRID + GRID), static_cast<float>(j * GRID + GRID));
            window.draw(singleField);
        }
    }
}
