#include "Game.h"

int main()
{
    //Game game(Player::Type::RandomPlayer, Player::Type::RandomPlayer);
    //game.play(20);

    ChessboardPrinter printer;
    Chessboard board("R6Q/8/1k6/NB6/8/1P2n3/1PPP1P1P/RNB3K1");
    std::vector<char> offsets;
    board.getTeamOffsets(Team::Player2, offsets);
    for (const auto& i : offsets)
        printer.printMoves(i, board);
}