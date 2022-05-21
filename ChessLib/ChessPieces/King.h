#pragma once
#include "../Piece.h"

class King : public Piece
{
public:
	explicit King(Team team);

	virtual Type getType() const override;
	virtual void getMoves(const Chessboard& chessboard, char pos, std::vector<char>& moves, std::vector<char>& captures) const override;
};