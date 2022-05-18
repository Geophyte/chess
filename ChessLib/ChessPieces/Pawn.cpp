#include "Pawn.h"

const std::array<char, 3> Pawn::directions1 = { -8, -7, -9 };
const std::array<char, 3> Pawn::directions2 = { 8, 7, 9 };

Pawn::Pawn(Team team)
	: Piece(team)
{
}

Piece::Type Pawn::getType() const
{
	return Piece::Type::Pawn;
}

void Pawn::getMoveDirections(std::vector<char>& direct) const
{
	if (team == Piece::Team::Player1)
		direct.assign(directions1.begin(), ++directions1.begin());
	else
		direct.assign(directions2.begin(), ++directions2.begin());
}

void Pawn::getCaptureDirections(std::vector<char>& direct) const
{
	if (team == Piece::Team::Player1)
		direct.assign(++directions1.begin(), directions1.end());
	else
		direct.assign(++directions2.begin(), directions2.end());
}