#include "Rook.h"
#include "../Chessboard.h"

Rook::Rook(Team team)
	: Piece(team)
{
}

Piece::Type Rook::getType() const
{
	return Piece::Type::Rook;
}

void Rook::getMoves(const Chessboard& cb, char pos, std::vector<char>& moves, std::vector<char>& captures) const
{
	static const std::vector<char> directions = { -8, -1, 1, 8 };

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