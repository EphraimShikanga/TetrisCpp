#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "constants.hpp"
#include "shapeMatrix.hpp"
// #include "Board.hpp"

class Piece
{
private:
    // Board board;
    sf::Texture texture;
    std::unordered_map<const int (*)[PieceSize], int> shapeColorMap{
        {OShape, 90},
        {IShape, 108},
        {JShape, 54},
        {LShape, 72},
        {SShape, 0},
        {ZShape, 18},
        {TShape, 36}};

public:
    sf::Vector2i position;
    sf::Sprite cells[PieceSize][PieceSize];
    // int cells[PieceSize][PieceSize];
    Piece();
    Piece(const int shape[PieceSize][PieceSize]);
    int getPositionX();
    int getPositionY();
    bool hasReachedBottom();
    void draw(sf::RenderWindow &window);
    void moveDown(const Board &board);
    void moveLeft(const Board &board);
    void moveRight(const Board &board);
    bool isCollision(const Piece &piece, const Board &board);
    void rotateClockwise();
    void rotateCounterClockwise();
    ~Piece();
};

Piece::Piece()
{
    const int(*shape)[PieceSize] = TShape;
    texture.loadFromFile("./tiles.png");
    for (int x = 0; x < PieceSize; ++x)
    {
        for (int y = 0; y < PieceSize; ++y)
        {
            // cells[x][y] = shape[x][y];
            if (shape[x][y] != 0)
            {
                cells[x][y].setTexture(texture);
                cells[x][y].setTextureRect(sf::IntRect(0, 0, 18, 18));
                cells[x][y].setScale(static_cast<float>(CellSize) / cells[x][y].getTextureRect().width,
                                     static_cast<float>(CellSize) / cells[x][y].getTextureRect().height);
                cells[x][y].setPosition(y * CellSize, x * BoardWidth);
            }
            
        }
    }
}

Piece::Piece(const int shape[PieceSize][PieceSize])
{
    int spriteColor = shapeColorMap[shape];
    texture.loadFromFile("./tiles.png");
    for (int x = 0; x < PieceSize; ++x)
    {
        for (int y = 0; y < PieceSize; ++y)
        {
            // cells[x][y] = shape[x][y];
            if (shape[x][y] != 0)
            {
                cells[x][y].setTexture(texture);
                cells[x][y].setTextureRect(sf::IntRect(spriteColor, 0, 18, 18));
                cells[x][y].setScale(static_cast<float>(CellSize) / cells[x][y].getTextureRect().width,
                                     static_cast<float>(CellSize) / cells[x][y].getTextureRect().height);
                cells[x][y].setPosition( 5, x * BoardWidth);
            }
        }
    }
}

int Piece::getPositionX()
{
    return position.x;
}

int Piece::getPositionY()
{
    return position.y;
}

void Piece::draw(sf::RenderWindow &window)
{
    for (int x = 0; x < PieceSize; ++x)
    {
        for (int y = 0; y < PieceSize; ++y)
        {
            window.draw(cells[x][y]);
        }
    }
}

void Piece::rotateClockwise()
{
    sf::Sprite temp[PieceSize][PieceSize];
    for (int x = 0; x < PieceSize; ++x)
    {
        for (int y = 0; y < PieceSize; ++y)
        {
            temp[x][y] = cells[x][y];
        }
    }

    for (int x = 0; x < PieceSize; ++x)
    {
        for (int y = 0; y < PieceSize; ++y)
        {
            cells[x][y] = temp[PieceSize - y - 1][x];
        }
    }

    for (int i = 0; i < PieceSize; ++i)
    {
        for (int j = 0; j < PieceSize; ++j)
        {
            if (cells[i][j].getTexture() != nullptr)
            {
                cells[i][j].setPosition(position.x + j * CellSize, position.y + i * CellSize);
            }
        }
    }
}

void Piece::rotateCounterClockwise()
{
    sf::Sprite temp[PieceSize][PieceSize];
    for (int x = 0; x < PieceSize; ++x)
    {
        for (int y = 0; y < PieceSize; ++y)
        {
            temp[x][y] = cells[x][y];
        }
    }

    for (int x = 0; x < PieceSize; ++x)
    {
        for (int y = 0; y < PieceSize; ++y)
        {
            cells[x][y] = temp[y][PieceSize - x - 1];
        }
    }

    for (int i = 0; i < PieceSize; ++i)
    {
        for (int j = 0; j < PieceSize; ++j)
        {
            if (cells[i][j].getTexture() != nullptr)
            {
                cells[i][j].setPosition(position.x + j * CellSize, position.y + i * CellSize);
            }
        }
    }
}

bool Piece::isCollision(const Piece &piece, const Board &board)
{
    for (int i = 0; i < PieceSize; ++i)
    {
        for (int j = 0; j < PieceSize; ++j)
        {
            if (piece.cells[i][j].getTexture() != nullptr)
            {
                // check if the new position is outside the game board
                int newX = piece.position.x + j * CellSize;
                int newY = piece.position.y + i * CellSize + CellSize;

                // std::cout << newX << std::endl;

                // Check if the new position is outside the game board or overlaps with a placed piece
                if (newX < 0 || newX >= WindowWidth || newY < 0 || newY >= WindowHeight)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Piece::moveLeft(const Board &board)
{
    position.x -= CellSize;
    if (isCollision(*this, board))
    {
        position.x += CellSize;
    }

    for (int i = 0; i < PieceSize; ++i)
    {
        for (int j = 0; j < PieceSize; ++j)
        {
            if (cells[i][j].getTexture() != nullptr)
            {
                cells[i][j].setPosition(position.x + j * CellSize, position.y + i * CellSize);
            }
        }
    }
}

void Piece::moveRight(const Board &board)
{
    position.x += CellSize;
    if (isCollision(*this, board))
    {
        position.x -= CellSize;
    }
    for (int i = 0; i < PieceSize; ++i)
    {
        for (int j = 0; j < PieceSize; ++j)
        {
            if (cells[i][j].getTexture() != nullptr)
            {
                cells[i][j].setPosition(position.x + j * CellSize, position.y + i * CellSize);
            }
        }
    }
}

void Piece::moveDown(const Board &board)
{
    std::cout << "move down" << std::endl;
    if (!isCollision(*this, board))
    {
        position.y += CellSize;
        // position.y -= CellSize;
        for (int i = 0; i < PieceSize; ++i)
        {
            for (int j = 0; j < PieceSize; ++j)
            {
                if (cells[i][j].getTexture() != nullptr)
                {
                    cells[i][j].setPosition(position.x + j * CellSize, position.y + i * CellSize);
                }
            }
        }
    }
    std::cout << position.y << std::endl;

}

bool Piece::hasReachedBottom()
{
    return position.y + CellSize * PieceSize - PieceSize >= WindowHeight;
}

Piece::~Piece()
{
}
