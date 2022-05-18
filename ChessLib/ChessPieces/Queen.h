#pragma once
#include "Bishop.h"
#include "Rook.h"

class Queen : public Piece
{
public:
	explicit Queen(Team team);

	virtual Type getType() const override;
	virtual void getMoveDirections(std::vector<char>& direct) const override;
private:
	static const std::array<char, 8> directions;
};