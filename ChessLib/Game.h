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
public:
	enum class Players {
		Computer, Human
	};
private:
	Chessboard board;
	ChessboardPrinter printer;
	Player* currPlayer = nullptr;
	Player* secondPlayer = nullptr;
	GameStatus status = GameStatus::None;
	bool isInCheck(Player* player) const;
	bool hasMoves(Player* player);
	void endGame() const;
public:
	explicit Game(Players first, Players second);
	~Game();
	void play();
};