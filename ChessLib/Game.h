#pragma once
#include "Board.h"
#include "Player.h"

enum class GameStatus {
	None, InCheck, WhiteWin, BlackWin
};

class Game
{
private:
	Player* player1;
	Player* player2;
	Player* currPlayer;
	GameStatus status = GameStatus::None;
	Board* board;
public:
	Game(Player* player1, Player* player2);
	bool makeMove(const Move& move);
	bool inCheck(const Player& player) const;
	void play();
	void endGame();
};