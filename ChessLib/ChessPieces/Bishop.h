#pragma once
#include "../Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Chessboard& chessboard, Team t, char pos);

	virtual Type getType() const override;
	virtual void getMoves(std::vector<Move>& moves) const override;
};