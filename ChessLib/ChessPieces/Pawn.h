#pragma once
#include "../Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Team team);

	virtual Type getType() const override;
	virtual void getMoves(const Chessboard& chessboard, char pos, std::vector<char>& moves, std::vector<char>& captures) const override;
};