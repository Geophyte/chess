#include "Piece.h"
#include "Chessboard.h"

Piece::Piece(Chessboard& chessboard, Team t, char pos)
	: chessboard(chessboard), team(t), pos(pos), cState(State::NotMoved), lState(cState)
{}

Team Piece::getTeam() const
{
	return team;
}

Piece::State Piece::getState() const
{
	return cState;
}

void Piece::setState(State s)
{
	cState = s;
}

void Piece::onMove(char p)
{
	if (cState == State::NotMoved)
		cState = State::FirstMove;
	pos = p;
}

void Piece::saveState()
{
	lState = cState;
}

void Piece::restoreState()
{
	cState = lState;
}

void Piece::onNextTurn()
{
	if (cState == State::FirstMove)
		cState = State::Moved;
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
		if (cState != State::NotMoved)
			return 1;
		else
			return 2;
	}

	return 0;
}

char Piece::getPos() const
{
	return pos;
}

void Piece::getMoves(const std::vector<char>& directions, std::vector<Move>& moves) const
{
	auto king = chessboard.getKing(team);

	for (const auto& direction : directions)
	{
		std::vector<std::pair<char, Piece*>> sBuff;
		chessboard.searchDirection(pos, direction, getMaxDistance(getType()), sBuff);

		char maxDistance = sBuff.size();
		for (int i = 0; i< maxDistance; i++)
		{
			if (!sBuff[i].second)
			{
				Move temp = { pos, sBuff[i].first, pos, sBuff[i].first, Move::Type::Move };
				if(!king->willIndangereKing(temp))
					moves.push_back(temp);
				continue;
			}
			else if (sBuff[i].second->getTeam() != team)
			{
				Move temp = { pos, sBuff[i].first, sBuff[i].first, sBuff[i].first, Move::Type::Capture };
				if(!king->willIndangereKing(temp))
					moves.push_back(temp);
			}

			break;
		}
	}
}

bool Move::operator<(const Move& other) const
{
	if(cDest != other.cDest)
		return cDest < other.cDest;
	return cStart < other.cStart;
}
