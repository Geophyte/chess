#pragma once
#include "Chessboard.h"
#include "ChessboardPrinter.h"
#include "Players/Player.h"


class Game
{
private:
	enum class GameStatus {
		None, InCheck, Stalemate, End
	};
private:
	Chessboard board;
	ChessboardPrinter printer;
	std::unique_ptr<Player> currPlayer = nullptr;
	std::unique_ptr<Player> secondPlayer = nullptr;
	GameStatus status = GameStatus::None;
	bool isInCheck(Player* player) const;
	bool hasMoves(Player* player);
	void endGame() const;
public:
	explicit Game(Player::Type first, Player::Type second);
	void play(unsigned delay = 0);	// Rozpoczyna rozgrywke, delay to czas miedzy rundami wyrazony w milisekundach
private:
	void initPlayer(Team team, Player::Type type, std::unique_ptr<Player>& player) const;
};