// #include <thread>
// #include <chrono>

#include "Board.hpp"
#include "Piece.hpp"
#include "Game.hpp"


int main(void)
{
    // sf::RenderWindow window(sf::VideoMode(300, 600), "Tetris");
    // Board board;
    // Piece piece(ZShape);
    // Piece piece;
    // Piece piece = Piece(IShape);
    // piece.setPosition(BoardWidth / 2, 0);
    Game game;
    game.run();
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         // Close window: exit
    //         if (event.type == sf::Event::Closed)
    //             window.close();
            
    //         if (event.type == sf::Event::KeyPressed)
    //         {
    //             if (event.key.code == sf::Keyboard::Left)
    //             {
    //                 piece.moveLeft(board);
    //             }
    //             else if (event.key.code == sf::Keyboard::Right)
    //             {
    //                 piece.moveRight(board);
    //             }
    //             else if (event.key.code == sf::Keyboard::Down)
    //             {
    //                 piece.moveDown(board);
    //             }
    //             else if (event.key.code == sf::Keyboard::X)
    //             {
    //                 piece.rotateClockwise();
    //             }
    //             else if (event.key.code == sf::Keyboard::Z)
    //             {
    //                 piece.rotateCounterClockwise();
    //             }
    //         }
    //     }


    //     window.clear(sf::Color::White);
    //     board.draw(window);
    //     piece.draw(window);
    //     piece.moveDown(board);
    //     window.display();
    //     std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // }

    return 0;
}