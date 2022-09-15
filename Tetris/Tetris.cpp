#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GlobalValues.hpp"
#include "Band.hpp"


using namespace sf;
using namespace std;

int main()
{
    RenderWindow window{ VideoMode{800, 600}, "Tetris" };
    window.setFramerateLimit(60);
    Event event;

    Band band(Vector2f{ NUMBER_OF_COLUMNS * GRID, NUMBER_OF_ROWS * GRID });

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
    window.draw(band);
    window.display();
    }

    return 0;
}
