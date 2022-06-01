#include "ChessboardPrinter.h"
#include "Chessboard.h"
#include "Game.h"

int main()
{
    Game game(Player::Type::RandomPlayer, Player::Type::RandomPlayer);
    game.play(2);

    //ChessboardPrinter printer;
    //Chessboard board("r3k2r/8/8/8/8/8/8/R3K2R");

    //std::vector<char> buffer;
    //board.getTeamOffsets(Team::Player2, buffer);
    //board.getTeamOffsets(Team::Player1, buffer);
    //for (const auto& i : buffer)
    //    printer.printMoves(i, board);
}