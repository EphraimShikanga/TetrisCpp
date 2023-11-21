#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include "Board.hpp"
#include "Piece.hpp"

class Game
{
private:
    sf::RenderWindow window;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;

public:
    Board board;
    Piece currentPiece;
    Piece nextPiece;

    Game();
    void run();
    void render();
    void Update();
    void handleInput();
    void spawnNextPiece();
};

Game::Game() : window(sf::VideoMode(WindowWidth, WindowHeight), "Tetris"), gen(rd()), dist(0, 6)
{
    Board board;
    Piece currentPiece = Piece(IShape);
    Piece nextPiece = Piece(TShape);
}

void Game::run()
{
    while (window.isOpen())
    {
        render();
        Update();
        handleInput();
    }
}

void Game::render()
{
    window.clear(sf::Color::White);
    board.draw(window);
    currentPiece.draw(window);
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Game::Update()
{
    if (currentPiece.hasReachedBottom())
    {
        // board.placePiece(currentPiece);
        spawnNextPiece();
    }
    else
    {
        currentPiece.moveDown(board);
    }

    // currentPiece.moveDown(board);
}

void Game::handleInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left)
            {
                currentPiece.moveLeft(board);
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                currentPiece.moveRight(board);
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                currentPiece.moveDown(board);
            }
            else if (event.key.code == sf::Keyboard::X)
            {
                currentPiece.rotateClockwise();
            }
            else if (event.key.code == sf::Keyboard::Z)
            {
                currentPiece.rotateCounterClockwise();
            }
        }
    }
}

void Game::spawnNextPiece()
{
    int random = dist(gen);
    switch (random)
    {
    case 0:
        currentPiece = Piece(IShape);
        break;
    case 1:
        currentPiece = Piece(JShape);
        break;
    case 2:
        currentPiece = Piece(LShape);
        break;
    case 3:
        currentPiece = Piece(OShape);
        break;
    case 4:
        currentPiece = Piece(SShape);
        break;
    case 5:
        currentPiece = Piece(TShape);
        break;
    case 6:
        currentPiece = Piece(ZShape);
        break;
    default:
        break;
    }
}

// Game game;
// try
// {
//     game.run();
// }
// catch (const std::exception &e)
// {
//     std::cerr << e.what() << '\n';
// }
// return 0;