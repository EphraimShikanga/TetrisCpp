#pragma once
#include <SFML/Graphics.hpp>

const int BoardWidth = 10;
const int BoardHeight = 20;
const int CellSize = 30;

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
                cell.setOutlineThickness(0.5f);
                cell.setOutlineColor(sf::Color::White);
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

private:
    sf::RectangleShape cells[BoardWidth][BoardHeight];
};