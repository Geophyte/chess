#pragma once
#include "Bishop.h"
#include "Rook.h"

class Queen : public Piece
{
public:
	explicit Queen(Team team);

	virtual Type getType() const override;
	virtual void getMoves(const Chessboard& chessboard, char pos, std::vector<char>& moves, std::vector<char>& captures) const override;
};