#include "ChessboardPrinter.h"
#include "Chessboard.h"
#include "Game.h"

int main()
{
    Game game(Game::Players::Human, Game::Players::Human);
    game.play();
}