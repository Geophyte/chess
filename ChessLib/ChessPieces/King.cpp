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

	//// Roszada
	//if (cState != State::NotMoved)
	//	return;

	//char row = pos / 8, col = pos % 8;
	//if ((row != 0 && row != 7) || col != 4)
	//	return;

	//static const std::vector<char> castlingDirs = { -1, 1 };
	//for (const auto& direction : castlingDirs)
	//{
	//	std::vector<std::pair<char, Piece*>> sBuff;
	//	chessboard.searchDirection(pos, direction, sBuff);

	//	bool canCastle = true;
	//	for (int i = 0; i < sBuff.size() - 1; i++)
	//		if (sBuff[i].second)
	//		{
	//			canCastle = false;
	//			break;
	//		}

	//	if(canCastle && sBuff.size() && sBuff.back().second)
	//		if (sBuff.back().second->getTeam() == team &&
	//			sBuff.back().second->getType() == Type::Rook &&
	//			sBuff.back().second->getState() == State::NotMoved)
	//		{
	//			Move temp;
	//			temp.cStart = pos;
	//			temp.cDest = pos + 2 * direction;
	//			temp.oStart = sBuff.back().first;
	//			temp.oDest = pos + direction;
	//			temp.type = Move::Type::Castling;

	//			if (willIndangereKing(temp))
	//				moves.push_back(temp);
	//		}
	//}
}

bool King::willIndangereKing(Move move) const
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
