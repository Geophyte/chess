#include "ChessboardPrinter.h"
#include "Chessboard.h"
#include "Game.h"

int main()
{
    Game game(Player::Type::RandomPlayer, Player::Type::RandomPlayer);
    game.play(200);

    //ChessboardPrinter printer;
    //Chessboard board("8/8/3k4/8/3K4/8/8/8");

    //std::vector<char> buffer;
    //board.getTeamOffsets(Team::Player2, buffer);
    //board.getTeamOffsets(Team::Player1, buffer);
    //for (const auto& i : buffer)
    //    printer.printMoves(i, board);
}