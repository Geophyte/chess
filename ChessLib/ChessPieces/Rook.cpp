#include "Rook.h"

const std::array<char, 4> Rook::directions = { -8, -1, 1, 8 };

Rook::Rook(Team team)
	: Piece(team)
{
}

Piece::Type Rook::getType() const
{
	return Piece::Type::Rook;
}

void Rook::getMoveDirections(std::vector<char>& direct) const
{
	direct.assign(directions.begin(), directions.end());
}