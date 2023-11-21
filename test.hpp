// #include "Board.hpp"
// #include "Pieces.hpp"
// #include "GameMechanics.hpp"

// void Piece::moveDown(const GameMechanics &gameMechanics, const Board &board)
// {
//     if (!gameMechanics.isCollision(*this, board))
//     {
//         position.y += CellSize;
//     }
// }

// bool GameMechanics::isCollision(const Piece &piece, const Board &board)
// {
//     for (int i = 0; i < PieceSize; ++i)
//     {
//         for (int j = 0; j < PieceSize; ++j)
//         {
//             if (piece.cells[i][j].getTexture() != nullptr)
//             {
//                 int newX = piece.position.x + j * CellSize;
//                 int newY = piece.position.y + i * CellSize + CellSize; // Move down by one cell

//                 // Check if the new position is outside the game board or overlaps with a placed piece
//                 if (newX < 0 || newX >= BoardWidth * CellSize || newY < 0 || newY >= BoardHeight * CellSize || board.cells[newY / CellSize][newX / CellSize].getTexture() != nullptr)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }
