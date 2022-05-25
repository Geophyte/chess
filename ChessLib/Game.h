//#pragma once
//#include "Board.h"
//#include "Player.h"
//
//enum class GameStatus {
//	None, InCheck, WhiteWin, BlackWin
//};
//
//class Game
//{
//private:
//	Player* player1;
//	Player* player2;
//	Player* currPlayer;
//	GameStatus status = GameStatus::None;
//	Board* board;
//public:
//	Game(Player* player1, Player* player2);
//	bool makeMove(const Move& move);
//	bool inCheck(const Player& player) const;
//	void play();
//	void endGame();
//};
#pragma once
#include "Chessboard.h"
#include "ChessboardPrinter.h"
#include "Players/Player.h"


class Game
{
private:
	enum class GameStatus {
		None, InCheck, End
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
	bool isGameOver(Player* player);
	void endGame() const;
public:
	explicit Game(Players first, Players second);
	~Game();
	void play();
};