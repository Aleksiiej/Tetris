#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>

#include "GlobalValues.hpp"
#include "Band.hpp"
#include "Block.hpp"
#include "blockBoard.hpp"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window{ VideoMode{800, 600}, "Tetris" };
    window.setFramerateLimit(60);
    Event event;

    Band band{ GRID, GRID };
    BlockBoard* blockBoardPtr = new BlockBoard;
    Block block{ 5 * GRID, 0, blockBoardPtr };

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
        for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
        {
            for (int j = 0; j < NUMBER_OF_ROWS; j++)
            {
                window.draw(blockBoardPtr->blockBoard_.at(i).at(j));
            }    
        }
        window.draw(block);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(GAME_SPEED));
    }
    return 0;
}
