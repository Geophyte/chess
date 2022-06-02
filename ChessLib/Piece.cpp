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

void Piece::setPos(char p)
{
	pos = p;
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

Piece::operator char() const
{
	char temp = static_cast<char>(getType());

	if (team == Team::Player1)
		temp = toupper(temp);

	return temp;
}

bool Piece::canMove() const
{
	std::vector<Move> moves;
	getMoves(moves);

	return moves.size();
}

bool Piece::canPromote() const
{
	return canPromote(pos);
}

bool Piece::canPromote(char pos) const
{
	return getType() == Type::Pawn && cState != State::NotMoved && (pos / 8 == 0 || pos / 8 == 7);
}

int Piece::getMaxDistance() const
{
	switch (getType())
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

void Piece::getMoves(std::vector<Move>& moves) const
{
	generateMoves(moves);
	removeIllegalMoves(moves);
}

void Piece::getMoves(const std::vector<char>& directions, std::vector<Move>& moves) const
{
	for (const auto& direction : directions)
	{
		std::vector<std::pair<char, Piece*>> sBuff;
		chessboard.searchDirection(pos, direction, getMaxDistance(), sBuff);

		char maxDistance = sBuff.size();
		for (int i = 0; i < maxDistance; i++)
		{
			if (!sBuff[i].second)
			{
				Move temp = { pos, sBuff[i].first, pos, sBuff[i].first, Move::Type::Move };
				moves.push_back(temp);
				continue;
			}
			else if (sBuff[i].second->getTeam() != team)
			{
				Move temp = { pos, sBuff[i].first, sBuff[i].first, sBuff[i].first, Move::Type::Capture };
				moves.push_back(temp);
			}

			break;
		}
	}
}

void Piece::removeIllegalMoves(std::vector<Move>& moves) const
{
	King* king = chessboard.getKing(team);
	std::vector<Move> result;

	for (const auto& move : moves)
		if (!king->willIndangereKing(move))
			result.push_back(move);
	moves = result;
}

bool Move::operator<(const Move& other) const
{
	if(cDest != other.cDest)
		return cDest < other.cDest;
	return cStart < other.cStart;
}
