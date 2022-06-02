#pragma once
#include "../Piece.h"

class Knight : public Piece
{
public:
	Knight(Chessboard& chessboard, Team t, char pos);

	virtual Type getType() const override;
	void generateMoves(std::vector<Move>& moves) const override;
};