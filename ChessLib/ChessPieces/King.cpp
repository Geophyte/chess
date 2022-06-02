#include "King.h"
#include "../Chessboard.h"

King::King(Chessboard& chessboard, Team team, char pos)
	: Piece(chessboard, team, pos)
{
}

Piece::Type King::getType() const
{
	return Piece::Type::King;
}
void King::generateMoves(std::vector<Move>& moves) const
{
	static const std::vector<char> directions = { -9, -8, -7, -1, 1, 7, 8, 9 };
	Piece::getMoves(directions, moves);

	// Roszada
	getCastling(moves);
}

bool King::willIndangereKing(const Move& move) const
{
	bool result;

	chessboard.makeMove(move);
	if (inCheck() >= 0)
		result = true;
	else
		result = false;
	chessboard.undoMove(move);

	return result;
}

char King::inCheck() const
{
	std::unique_ptr<Piece> pieces[6];
	pieces[0] = std::make_unique<King>(chessboard, team, pos);
	pieces[1] = std::make_unique<Queen>(chessboard, team, pos);
	pieces[2] = std::make_unique<Bishop>(chessboard, team, pos);
	pieces[3] = std::make_unique<Knight>(chessboard, team, pos);
	pieces[4] = std::make_unique<Rook>(chessboard, team, pos);
	pieces[5] = std::make_unique<Pawn>(chessboard, team, pos);
	
	for (const auto& piece : pieces)
	{
		std::vector<Move> moves;
		auto t = piece->getType();
		piece->generateMoves(moves);
		for (const auto& move : moves)
			if (move.type == Move::Type::Capture && chessboard.getPiece(move.cDest)->getType() == piece->getType())
				return move.cDest;
	}

	return -1;
}

void King::getCastling(std::vector<Move>& moves) const
{
	char lRookOff = pos - 4;
	char rRookOff = pos + 3;
	Rook* lRook = nullptr;
	Rook* rRook = nullptr;

	if (0 <= lRookOff)
		lRook = dynamic_cast<Rook*>(chessboard.getPiece(pos - 4));
	if(rRookOff < 64)
		rRook = dynamic_cast<Rook*>(chessboard.getPiece(pos + 3));

	if (lRook)
		lRook->getCastling(moves);
	if (rRook)
		rRook->getCastling(moves);
}
