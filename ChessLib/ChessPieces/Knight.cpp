#include "Knight.h"

const std::array<char, 8> Knight::directions = { -17,-15,-10,-6,6,10,15,17 };

Knight::Knight(Team team)
	: Piece(team)
{
}

Piece::Type Knight::getType() const
{
	return Piece::Type::Knight;
}

void Knight::getMoveDirections(std::vector<char>& direct) const
{
	direct.assign(directions.begin(), directions.end());
}