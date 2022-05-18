#include "Bishop.h"

const std::array<char, 4> Bishop::directions = { -9, -7, 7, 9 };

Bishop::Bishop(Team team)
	: Piece(team)
{
}

Piece::Type Bishop::getType() const
{
	return Piece::Type::Bishop;
}

void Bishop::getMoveDirections(std::vector<char>& direct) const
{
	direct.assign(directions.begin(), directions.end());
}
