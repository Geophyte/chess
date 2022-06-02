#pragma once
#include "../Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Chessboard& chessboard, Team t, char pos);

	virtual Type getType() const override;
	void generateMoves(std::vector<Move>& moves) const override;
};