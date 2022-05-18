#include "Queen.h"

const std::array<char, 8> Queen::directions = { -9, -8, -7, -1, 1, 7, 8, 9 };

Queen::Queen(Team team)
	: Piece(team)
{
}

Piece::Type Queen::getType() const
{
	return Piece::Type::Queen;
}

void Queen::getMoveDirections(std::vector<char>& direct) const
{
	direct.assign(directions.begin(), directions.end());
}