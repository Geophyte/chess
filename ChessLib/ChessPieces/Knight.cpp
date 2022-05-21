#include "Knight.h"
#include "../Chessboard.h"

Knight::Knight(Team team)
	: Piece(team)
{
}

Piece::Type Knight::getType() const
{
	return Piece::Type::Knight;
}

void Knight::getMoves(const Chessboard& cb, char pos, std::vector<char>& moves, std::vector<char>& captures) const
{
	static const std::vector<char> directions = { -17,-15,-10,-6,6,10,15,17 };

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