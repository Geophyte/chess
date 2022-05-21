#include "Bishop.h"
#include "../Chessboard.h"

Bishop::Bishop(Team team)
	: Piece(team)
{
}

Piece::Type Bishop::getType() const
{
	return Piece::Type::Bishop;
}

void Bishop::getMoves(const Chessboard& cb, char pos, std::vector<char>& moves, std::vector<char>& captures) const
{
	static const std::vector<char> directions = { -9, -7, 7, 9 };

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
