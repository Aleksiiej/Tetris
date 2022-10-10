#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Band.hpp"
#include "BlockBoard.hpp"
#include "Block1.hpp"
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

    const Band band{ GRID, GRID };
    const auto blockBoardPtr = make_shared<BlockBoard>();
    Block1 block1{blockBoardPtr};
    const EndgameText endgameText;
    GameStatus gameStatus{GameStatus::Ongoing};

    while (true)
    {
        window.clear(Color::White);
        if (!block1.checkIfLost())
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
                    block1.moveRight();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Left)
                {
                    block1.moveLeft();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Down)
                {
                    block1.moveDown();
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
        for (const auto& block : block1.getBlock1ArrayRef())
        {
            window.draw(block);
        }
        window.display();
        sleep(milliseconds(GAME_SPEED));
        block1.fall();
    }
    return 0;
}

void drawBoard(const Band& band, const shared_ptr<BlockBoard>& blockBoardPtr, RenderWindow& window) noexcept
{
        window.draw(band);
        for (const auto& innerArray : blockBoardPtr->getBoardArrayRef())
        {
            for_each(begin(innerArray), end(innerArray), [&window](const auto& block) { window.draw(block); });
        }
}
