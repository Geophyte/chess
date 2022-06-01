#pragma once
#include "Player.h"
#include <random>

class RandomPlayer : public Player
{
public:
	RandomPlayer(Team team);
	virtual Move getMove(const Chessboard& board, const ChessboardPrinter& printer) const;
	virtual Piece::Type getPromotion() const;
private:
	std::random_device rd;
	mutable std::mt19937 gen;
};