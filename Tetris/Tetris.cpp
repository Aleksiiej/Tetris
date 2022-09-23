#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

#include "Band.hpp"
#include "Block.hpp"
#include "BlockBoard.hpp"
#include "GlobalValues.hpp"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window{ VideoMode{800, 600}, "Tetris" };
    window.setFramerateLimit(60);
    Event event;

    const Band band{ GRID, GRID };
    auto blockBoardPtr = make_shared<BlockBoard>();
    Block block{ 5 * GRID, GRID, blockBoardPtr };

    while (true)
    {
        window.clear(Color::White);
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
        }
        block.fall();
        window.draw(band);
        for (const auto& innerArray : blockBoardPtr->getBoardArrayRef())
        {
            for_each(begin(innerArray), end(innerArray), [&window](const auto& block) { window.draw(block.getBlockRef()); });
        }
        window.draw(block);
        window.display();
        sleep(milliseconds(GAME_SPEED));
    }
    return 0;
}
