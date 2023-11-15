#include "Board.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 600), "Tetris");
    Board board;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        board.draw(window);
        window.display();
    }

    return 0;
}