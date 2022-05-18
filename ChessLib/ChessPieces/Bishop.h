#pragma once
#include "../Piece.h"

class Bishop : public Piece
{
public:
	explicit Bishop(Team team);

	virtual Type getType() const override;
	virtual void getMoveDirections(std::vector<char>& direct) const override;
private:
	static const std::array<char, 4> directions;
};