#pragma once
#include "../Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Chessboard& chessboard, Team team, char pos);

	virtual Type getType() const override;
	void generateMoves(std::vector<Move>& moves) const override;
};