#include "Bishop.h"
#include "../Chessboard.h"

Bishop::Bishop(Chessboard& chessboard, Team team, char pos)
	: Piece(chessboard, team, pos)
{
}

Piece::Type Bishop::getType() const
{
	return Piece::Type::Bishop;
}

void Bishop::getMoves(std::vector<Move>& moves) const
{
	static const std::vector<char> directions = { -9, -7, 7, 9 };
	Piece::getMoves(directions, moves);
	removeIllegalMoves(moves);
}
