#include "Rook.h"
#include "../Chessboard.h"

Rook::Rook(Chessboard& chessboard, Team team, char pos)
	: Piece(chessboard, team, pos)
{
}

Piece::Type Rook::getType() const
{
	return Piece::Type::Rook;
}

void Rook::getMoves(std::vector<Move>& moves) const
{
	static const std::vector<char> moveDirs = { -8, -1, 1, 8 };
	Piece::getMoves(moveDirs, moves);
	auto king = chessboard.getKing(team);

	// Roszada
	if (cState != State::NotMoved)
		return;

	char row = pos / 8, col = pos % 8;
	if ((row != 0 && row != 7) || (col != 0 && col != 7))
		return;

	char castlingDir = col ? -1 : 1;
	std::vector<std::pair<char, Piece*>> sBuff;
	chessboard.searchDirection(pos, castlingDir, sBuff);

	bool canCastle = true;
	char maxDistance = col ? 2 : 3;
	for (int i = 0; i < maxDistance; i++)
		if (sBuff[i].second)
		{
			canCastle = false;
			break;
		}

	if(canCastle && sBuff[maxDistance].second)
		if (sBuff[maxDistance].second->getTeam() == team &&
			sBuff[maxDistance].second->getType() == Type::King &&
			sBuff[maxDistance].second->getState() == State::NotMoved)
		{
			Move temp;
			temp.cStart = pos;
			temp.cDest = pos + maxDistance * castlingDir;
			temp.oStart = sBuff[maxDistance].first;
			temp.oDest = sBuff[maxDistance].first - 2 * castlingDir;
			temp.type = Move::Type::Castling;

			if(!king->willIndangereKing(temp))
				moves.push_back(temp);
		}
}