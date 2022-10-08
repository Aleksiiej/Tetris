#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

#include "Band.hpp"
#include "BlockBoard.hpp"
#include "Block1.hpp"
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
    Block1 Block1{blockBoardPtr};
    EndgameText endgameText;
    GameStatus gameStatus{GameStatus::Ongoing};

    while (true)
    {
        window.clear(Color::White);
        if (!Block1.checkIfLost())
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
                    Block1.moveRight();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Left)
                {
                    Block1.moveLeft();
                }
                if (event.type == Event::EventType::KeyPressed and event.key.code == Keyboard::Down)
                {
                    Block1.moveDown();
                }
            }
        }
        else
        {
            window.draw(band);
            for (auto& innerArray : blockBoardPtr->getBoardArrayRef())
            {
                for_each(begin(innerArray), end(innerArray), [&window](auto& block) { window.draw(block); });
            }
            window.draw(endgameText);
            window.display();
            sleep(milliseconds(2000));
            window.close();
            return 0;
        }
        window.draw(band);
        for (auto& innerArray : blockBoardPtr->getBoardArrayRef())
        {
            for_each(begin(innerArray), end(innerArray), [&window](auto& block) { window.draw(block); });
        }
        window.draw(Block1.getBlock1Ref());
        window.draw(Block1.getBlock2Ref());
        window.draw(Block1.getBlock3Ref());
        window.draw(Block1.getBlock4Ref());
        window.display();
        sleep(milliseconds(GAME_SPEED));
        Block1.fall();
    }
    return 0;
}
