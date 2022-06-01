#include "Game.h"

int main()
{
    Game game(Player::Type::HumanPlayer, Player::Type::RandomPlayer);
    game.play(200);
}