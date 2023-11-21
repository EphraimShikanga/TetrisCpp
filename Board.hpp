#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.hpp"


class Board
{
public:
    Board()
    {
        for (int x = 0; x < BoardWidth; ++x)
        {
            for (int y = 0; y < BoardHeight; ++y)
            {
                sf::RectangleShape cell(sf::Vector2f(CellSize, CellSize));
                cell.setFillColor(sf::Color::Transparent);
                cell.setOutlineThickness(0.5);
                cell.setOutlineColor(sf::Color::Black);
                cell.setPosition(x * CellSize, y * CellSize);
                cells[x][y] = cell;
            }
        }
    }

    void draw(sf::RenderWindow &window)
    {
        for (int x = 0; x < BoardWidth; ++x)
        {
            for (int y = 0; y < BoardHeight; ++y)
            {
                window.draw(cells[x][y]);
            }
        }
    }
    sf::RectangleShape cells[BoardWidth][BoardHeight];

private:
};