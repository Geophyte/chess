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

void Rook::generateMoves(std::vector<Move>& moves) const
{
	static const std::vector<char> moveDirs = { -8, -1, 1, 8 };
	Piece::getMoves(moveDirs, moves);
	auto king = chessboard.getKing(team);

	// Roszada
	getCastling(moves);
}

void Rook::getCastling(std::vector<Move>& moves) const
{
	char row = pos / 8, col = pos % 8;
	if (cState == State::NotMoved && (row == 0 || row == 7) && (col == 0 || col == 7))
	{
		char castlingDir = col ? -1 : 1;
		std::vector<std::pair<char, Piece*>> sBuff;

		char maxDistance = col ? 3 : 4;
		chessboard.searchDirection(pos, castlingDir, maxDistance, sBuff);

		for (char i = 0; i < maxDistance - 1; i++)
			if (sBuff[i].second)
				return;

		if (sBuff.back().second)
			if (sBuff.back().second->getTeam() == team &&
				sBuff.back().second->getType() == Type::King &&
				sBuff.back().second->getState() == State::NotMoved)
			{
				Move temp;
				temp.cStart = sBuff.back().first;
				temp.cDest = sBuff.back().first - 2 * castlingDir;
				temp.oStart = pos;
				temp.oDest = sBuff.back().first - castlingDir;
				temp.type = Move::Type::Castling;
				moves.push_back(temp);
			}
	}
}
