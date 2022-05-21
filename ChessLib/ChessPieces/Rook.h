#pragma once
#include "../Piece.h"

class Rook : public Piece
{
public:
	Rook(Team team);

	virtual Type getType() const override;
	virtual void getMoves(const Chessboard& chessboard, char pos, std::vector<char>& moves, std::vector<char>& captures) const override;
};