#include "ChessboardPrinter.h"
#include "Chessboard.h"

int main()
{
    ChessboardPrinter printer;

    {
        Chessboard chessboard("1k4qr/8/8/8/8/8/8/R3K2R");
        std::vector<char> offsets;
        chessboard.getTeamOffsets(Team::Player2, offsets);
        chessboard.getTeamOffsets(Team::Player1, offsets);
        for (const auto& i : offsets)
            printer.printMoves(i, chessboard);
    }
}