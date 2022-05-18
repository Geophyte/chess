#include "King.h"

const std::array<char, 8> King::directions = { -9, -8, -7, -1, 1, 7, 8, 9 };

King::King(Team team)
	: Piece(team)
{
}

Piece::Type King::getType() const
{
	return Piece::Type::King;
}

void King::getMoveDirections(std::vector<char>& direct) const
{
	direct.assign(directions.begin(), directions.end());
}