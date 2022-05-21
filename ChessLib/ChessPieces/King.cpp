#include "King.h"
#include "../Chessboard.h"

King::King(Team team)
	: Piece(team)
{
}

Piece::Type King::getType() const
{
	return Piece::Type::King;
}

void King::getMoves(const Chessboard& cb, char pos, std::vector<char>& moves, std::vector<char>& captures) const
{
	static const std::vector<char> directions = { -9, -8, -7, -1, 1, 7, 8, 9 };

	char maxDistance = getMaxDistance(getType());

	for (const auto& direction : directions)	// wybieramy kierunek wzd³u¿ którego bêdziemy siê poruszaæ
	{
		char nextPos;
		char currentPos = pos;
		for (int i = 0; i < maxDistance; i++)
		{
			nextPos = currentPos + direction;

			if (!cb.canMoveStep(currentPos, nextPos))
				break;
			currentPos = nextPos;

			if (!cb[currentPos])
				moves.push_back(currentPos);
			else if (cb[currentPos]->getTeam() != team)
			{
				captures.push_back(currentPos);
				break;
			}
			else
				break;
		}
	}
}