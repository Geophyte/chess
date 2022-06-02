#include "Game.h"

int main()
{
    //Game game(Player::Type::RandomPlayer, Player::Type::RandomPlayer);
    //game.play(20);

    ChessboardPrinter printer;
    Chessboard board("k7/2K5/8/8/8/8/8/8");
    std::vector<char> offsets;
    board.getTeamOffsets(Team::Player2, offsets);
    board.getTeamOffsets(Team::Player1, offsets);
    for (const auto& i : offsets)
        printer.printMoves(i, board);
}