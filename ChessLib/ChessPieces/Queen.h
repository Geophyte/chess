#pragma once
#include "Bishop.h"
#include "Rook.h"

class Queen : public Piece
{
public:
	Queen(Chessboard& chessboard, Team team, char pos);

	virtual Type getType() const override;
	virtual void getMoves(std::vector<Move>& moves) const override;
};