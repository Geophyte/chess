#pragma once
#include "../Piece.h"

class Rook : public Piece
{
public:
	Rook(Team team);

	virtual Type getType() const override;
	virtual void getMoveDirections(std::vector<char>& direct) const override;
private:
	static const std::array<char, 4> directions;
};