#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

#include "Band.hpp"
#include "Block.hpp"
#include "BlockBoard.hpp"
#include "Chunk1.hpp"
#include "EndgameText.hpp"
#include "GlobalValues.hpp"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window{ VideoMode{800, 600}, "Tetris" };
    window.setFramerateLimit(60);
    Event event;

    const Band band{ GRID, GRID };
    const auto blockBoardPtr = make_shared<BlockBoard>();
    Block block{ 5 * GRID, GRID, blockBoardPtr };
    Chunk1 chunk1;
    EndgameText endgameText;
    GameStatus gameStatus{GameStatus::Ongoing};

    while (true)
    {
        window.clear(Color::White);
        if (!block.checkIfLost())
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
                    block.moveRight();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Left)
                {
                    block.moveLeft();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Down)
                {
                    block.moveDown();
                }
            }
        }
        else
        {
            window.draw(band);
            for (auto& innerArray : blockBoardPtr->getBoardArrayRef())
            {
                for_each(begin(innerArray), end(innerArray), [&window](auto& block) { window.draw(block.getBlockRef()); });
            }
            window.draw(block);
            window.draw(endgameText);
            window.display();
            sleep(milliseconds(2000));
            window.close();
            return 0;
        }
        window.draw(band);
        for (auto& innerArray : blockBoardPtr->getBoardArrayRef())
        {
            for_each(begin(innerArray), end(innerArray), [&window](auto& block) { window.draw(block.getBlockRef()); });
        }
        window.draw(block);
        window.draw(chunk1.block1_);
        window.draw(chunk1.block2_);
        window.draw(chunk1.block3_);
        window.draw(chunk1.block4_);
        window.display();
        sleep(milliseconds(GAME_SPEED));
        block.fall();
    }
    return 0;
}
