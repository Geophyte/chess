#include <iostream>

#include "Chessboard.h"

int main()
{
    Chessboard chessboard;

    chessboard.SetTile('a', 8, 'r', COLOR_RED);
    chessboard.SetTile('b', 8, 'n', COLOR_RED);
    chessboard.SetTile('c', 8, 'b', COLOR_RED);
    chessboard.SetTile('d', 8, 'k', COLOR_RED);
    chessboard.SetTile('e', 8, 'q', COLOR_RED);
    chessboard.SetTile('f', 8, 'b', COLOR_RED);
    chessboard.SetTile('g', 8, 'n', COLOR_RED);
    chessboard.SetTile('h', 8, 'r', COLOR_RED);
    for(int i=0; i<8; ++i)
        chessboard.SetTile(i + 'a', 7, 'p', COLOR_RED);

    chessboard.SetTile('a', 1, 'r', COLOR_BLUE);
    chessboard.SetTile('b', 1, 'n', COLOR_BLUE);
    chessboard.SetTile('c', 1, 'b', COLOR_BLUE);
    chessboard.SetTile('d', 1, 'k', COLOR_BLUE);
    chessboard.SetTile('e', 1, 'q', COLOR_BLUE);
    chessboard.SetTile('f', 1, 'b', COLOR_BLUE);
    chessboard.SetTile('g', 1, 'n', COLOR_BLUE);
    chessboard.SetTile('h', 1, 'r', COLOR_BLUE);
    for (int i = 0; i < 8; ++i)
        chessboard.SetTile(i + 'a', 2, 'p', COLOR_BLUE);

    chessboard.Print();
}