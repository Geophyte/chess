#include "Pawn.h"
#include "../Chessboard.h"

Pawn::Pawn(Team team)
	: Piece(team)
{
}

Piece::Type Pawn::getType() const
{
	return Piece::Type::Pawn;
}

void Pawn::getMoves(const Chessboard& cb, char pos, std::vector<char>& moves, std::vector<char>& captures) const
{
	char moveDirection;
	std::vector<char> captureDirections;
	char maxDistance = getMaxDistance(getType());

	if (team == Piece::Team::Player1)
	{
		moveDirection = -8;
		captureDirections = { -7, -9 };
	}
	else
	{
		moveDirection = 8;
		captureDirections = { 7, 9 };
	}

	{
		char nextPos;
		char currentPos = pos;
		for (int i = 0; i < maxDistance; i++)
		{
			nextPos = currentPos + moveDirection;

			if (!cb.canMoveStep(currentPos, nextPos))
				break;
			currentPos = nextPos;

			if (!cb[currentPos])
				moves.push_back(currentPos);
		}
	}

	for (const auto& dircetion : captureDirections)
	{
		char nextPos = pos + dircetion;
		char currentPos = pos;

		if (!cb.canMoveStep(currentPos, nextPos))
			break;
		currentPos = nextPos;

		if (cb[currentPos])
			if (cb[currentPos]->getTeam() != team)
				captures.push_back(currentPos);

		// TO DO
		// Dodac wykrywanie bicia w przelocie
	}

}