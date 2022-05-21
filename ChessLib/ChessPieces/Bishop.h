#pragma once
#include "../Piece.h"

class Bishop : public Piece
{
public:
	explicit Bishop(Team team);

	virtual Type getType() const override;
	virtual void getMoves(const Chessboard& chessboard, char pos, std::vector<char>& moves, std::vector<char>& captures) const override;
};