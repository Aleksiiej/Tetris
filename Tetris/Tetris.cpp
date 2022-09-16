#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>

#include "GlobalValues.hpp"
#include "Band.hpp"
#include "Block.hpp"


using namespace sf;
using namespace std;

int main()
{
    RenderWindow window{ VideoMode{800, 600}, "Tetris" };
    window.setFramerateLimit(60);
    Event event;

    Band band{ GRID, GRID };
    Block block{ 5 * GRID, GRID };

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
        }
        block.fall();
        window.draw(band);
        window.draw(block);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(GAME_SPEED));
    }
    return 0;
}
