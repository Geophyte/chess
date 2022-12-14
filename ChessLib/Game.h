#pragma once
#include "Chessboard.h"
#include "ChessboardPrinter.h"
#include "Players/Player.h"
#include "FileMoveWriter.h"
#include "GameStatus.h"


/// Klasa odpowiadajaca za caly cykl gry.
/// Sposrod zadan klasy sa zarzadznie obiektami gry (pionki, szachownica)
/// oraz sprawdzenie wszystkich warunkow logicznych gry (np. okreslenie statusu rozrywki).
class Game
{
private:
	int movesPlayed = 0;
	Chessboard board;
	ChessboardPrinter printer;
	FileMoveWriter writer;
	std::unique_ptr<Player> currPlayer = nullptr;
	std::unique_ptr<Player> secondPlayer = nullptr;
	GameStatus status = GameStatus::None;
	bool isInCheck(Player* player) const;
	bool onlyKingsLeft() const;
	bool hasMoves(Player* player);
	void endGame() const;
public:
	explicit Game(Player::Type first, Player::Type second);
	void play(unsigned delay = 0);	// Rozpoczyna rozgrywke, delay to czas miedzy rundami wyrazony w milisekundach
private:
	void initPlayer(Team team, Player::Type type, std::unique_ptr<Player>& player) const;
};