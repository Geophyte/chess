#include "Knight.h"
#include "../Chessboard.h"

Knight::Knight(Chessboard& chessboard, Team team, char pos)
	: Piece(chessboard, team, pos)
{
}

Piece::Type Knight::getType() const
{
	return Piece::Type::Knight;
}

void Knight::generateMoves(std::vector<Move>& moves) const
{
	static const std::vector<char> directions = { -17,-15,-10,-6,6,10,15,17 };
	Piece::getMoves(directions, moves);
}
