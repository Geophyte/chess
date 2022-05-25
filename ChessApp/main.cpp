#include "ChessboardPrinter.h"
#include "Chessboard.h"
#include "Game.h"

int main()
{   /*
    ChessboardPrinter printer;

    {
        Chessboard chessboard("p7/8/2P3p1/1P4P1/8/5p1p/1P4P1/p7");
        printer.printMoves(25, chessboard); // B5
        printer.printMoves(30, chessboard); // G5
        printer.printMoves(49, chessboard); // B2
        printer.printMoves(54, chessboard); // G2
    }
    {
        Chessboard chessboard("8/8/1p4P1/8/8/8/1R4R1/R7");
        printer.printMoves(56, chessboard); // A1
        printer.printMoves(49, chessboard); // B2
        printer.printMoves(54, chessboard); // G2
    }
    {
        Chessboard chessboard("8/8/8/3pp3/3pp3/2N2N2/P6P/NP4P1");
        printer.printMoves(56, chessboard); // A1
        printer.printMoves(42, chessboard); // C3
        printer.printMoves(45, chessboard); // F3
    }
    {
        Chessboard chessboard("8/8/1p6/4p3/8/4Q1P1/8/Q7");
        printer.printMoves(56, chessboard); // A1
        printer.printMoves(44, chessboard); // E3
    }
    {
        Chessboard chessboard("8/8/8/8/4P3/4K3/p7/K7");
        printer.printMoves(56, chessboard); // A1
        printer.printMoves(44, chessboard); // E3
    }
    */
    Game game(Game::Players::Human, Game::Players::Human);
    game.play();
}