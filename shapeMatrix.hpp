const int PieceSize = 5;

const int TShape[PieceSize][PieceSize] = {
    {0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0 },
    {0, 1, 2, 1, 0 },
    {0, 0, 1, 0, 0 },
    {0, 0, 0, 0, 0 }
}; // Red(36, 0, 18, 18)

const int OShape[PieceSize][PieceSize] = {
    {0, 0, 0, 0, 0 },
    {0, 2, 1, 0, 0 },
    {0, 1, 1, 0, 0 },
    {0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0 }
}; // LightBlue(90, 0, 18, 18)

const int IShape[PieceSize][PieceSize] = {
    {0, 0, 0, 0, 0 },
    {0, 0, 1, 0, 0 },
    {0, 0, 2, 0, 0 },
    {0, 0, 1, 0, 0 },
    {0, 0, 0, 0, 0 }
}; // Orange(108, 0, 18, 18)

const int JShape[PieceSize][PieceSize] = {
    {0, 0, 0, 0, 0 },
    {0, 1, 0, 0, 0 },
    {0, 2, 1, 1, 0 },
    {0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0 }
}; // Green(54, 0, 18, 18)

const int LShape[PieceSize][PieceSize] = {
    {0, 0, 0, 0, 0 },
    {0, 0, 0, 1, 0 },
    {0, 1, 1, 2, 0 },
    {0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0 }
}; // Yellow(72, 0, 18, 18)

const int SShape[PieceSize][PieceSize] = {
    {0, 0, 0, 0, 0 },
    {0, 0, 1, 1, 0 },
    {0, 1, 2, 0, 0 },
    {0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0 }
}; // Blue(0, 0, 18, 18)

const int ZShape[PieceSize][PieceSize] = {
    {0, 0, 0, 0, 0 },
    {0, 1, 1, 0, 0 },
    {0, 0, 2, 1, 0 },
    {0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0 }
}; // Purple(18, 0, 18, 18)