#include "Piece.h"
#include "Chessboard.h"

Piece::Piece(Team t)
	: lastDistance(0), team(t)
{}

Team Piece::getTeam() const
{
	return team;
}

char Piece::getLastDistance() const
{
	return lastDistance;
}

void Piece::onMove(char dist)
{
	lastDistance = dist;
}

Piece::operator char()
{
	char temp = static_cast<char>(getType());

	if (team == Team::Player1)
		temp = toupper(temp);

	return temp;
}

int Piece::getMaxDistance(Type type) const
{
	switch (type)
	{
	case Piece::Type::Rook:
	case Piece::Type::Bishop:
	case Piece::Type::Queen:
		return 7;
	case Piece::Type::Knight:
	case Piece::Type::King:
		return 1;
	case Piece::Type::Pawn:
		if (lastDistance)
			return 1;
		else
			return 2;
	}

	return 0;
}
