#include "Queen.h"
#include "../Chessboard.h"

Queen::Queen(Chessboard& chessboard, Team team, char pos)
	: Piece(chessboard, team, pos)
{
}

Piece::Type Queen::getType() const
{
	return Piece::Type::Queen;
}

void Queen::getMoves(std::vector<Move>& moves) const
{
	static const std::vector<char> directions = { -9, -8, -7, -1, 1, 7, 8, 9 };
	Piece::getMoves(directions, moves);
	removeIllegalMoves(moves);
}