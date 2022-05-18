#pragma once
#include "../Piece.h"

class Knight : public Piece
{
public:
	Knight(Team team);

	virtual Type getType() const override;
	virtual void getMoveDirections(std::vector<char>& direct) const override;
private:
	static const std::array<char, 8> directions;
};