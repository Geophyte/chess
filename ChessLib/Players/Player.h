#pragma once
#include "../Chessboard.h"
#include "../ChessboardPrinter.h"

/// Klasa bazowa dla wszystkich graczy.
/// Glownym zadaniem klasy jest pobieranie ruchow graczy
/// zgodnie z regulami gry.
class Player
{
protected:
	Team team;
public:
	enum class Type {
		HumanPlayer, RandomPlayer
	};
public:
	Player(Team team) : team(team) {}
	Team getTeam() const { return team; }
	virtual Move getMove(const Chessboard& board, const ChessboardPrinter& printer) const = 0;
	virtual Piece::Type getPromotion() const = 0;
};