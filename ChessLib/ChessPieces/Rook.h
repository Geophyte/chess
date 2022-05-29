#pragma once
#include "../Piece.h"

class Rook : public Piece
{
public:
	Rook(Chessboard& chessboard, Team team, char pos);

	virtual Type getType() const override;
	virtual void getMoves(std::vector<Move>& moves) const override;
};