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

void King::getMoves(std::vector<Move>& moves) const
{
	static const std::vector<char> directions = { -9, -8, -7, -1, 1, 7, 8, 9 };
	Piece::getMoves(directions, moves);

	// Roszada
	getCastling(moves);

	removeIllegalMoves(moves);
}

bool King::willIndangereKing(const Move& move) const
{
	bool result;

	chessboard.makeMove(move);
	if (inCheck() > 0)
		result = true;
	else
		result = false;
	chessboard.undoMove(move);

	return result;
}

char King::inCheck() const
{
	std::vector<char> directions = { -8, -1, 1, 8 };
	for (const auto& direction : directions)
	{
		std::vector<std::pair<char, Piece*>> sBuff;
		chessboard.searchDirection(pos, direction, sBuff);

		for (const auto& i : sBuff)
			if (i.second)
				if (i.second->getTeam() != team &&
					(i.second->getType() == Type::Rook ||
						i.second->getType() == Type::Queen))
					return i.first;
				else
					break;
	}

	directions = { -7, -9, 7, 9 };
	for (const auto& direction : directions)
	{
		std::vector<std::pair<char, Piece*>> sBuff;
		chessboard.searchDirection(pos, direction, sBuff);

		for (const auto& i : sBuff)
			if (i.second)
				if (i.second->getTeam() != team &&
					(i.second->getType() == Type::Bishop ||
						i.second->getType() == Type::Queen))
					return i.first;
				else
					break;
	}

	directions = { -17,-15,-10,-6,6,10,15,17 };
	for (const auto& direction : directions)
	{
		std::vector<std::pair<char, Piece*>> sBuff;
		chessboard.searchDirection(pos, direction, 1, sBuff);

		for (const auto& i : sBuff)
			if (i.second)
				if (i.second->getTeam() != team &&
					i.second->getType() == Type::Knight)
					return i.first;
				else
					break;
	}

	if(team == Team::Player1)
		directions = { -7, -9 };
	else
		directions = { 7, 9 };

	for (const auto& direction : directions)
	{
		std::vector<std::pair<char, Piece*>> sBuff;
		chessboard.searchDirection(pos, direction, 1, sBuff);

		for (const auto& i : sBuff)
			if (i.second)
				if (i.second->getTeam() != team &&
					i.second->getType() == Type::Pawn)
					return i.first;
				else
					break;
	}

	return -1;
}

void King::getCastling(std::vector<Move>& moves) const
{
	Rook* lRook = dynamic_cast<Rook*>(chessboard.getPiece(pos - 4));
	Rook* rRook = dynamic_cast<Rook*>(chessboard.getPiece(pos + 3));

	if (lRook)
		lRook->getCastling(moves);
	if (rRook)
		rRook->getCastling(moves);
}
