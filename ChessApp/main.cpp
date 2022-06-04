#include "Game.h"

int main()
{
    Game game(Player::Type::RandomPlayer, Player::Type::RandomPlayer);
    game.play(200);
}