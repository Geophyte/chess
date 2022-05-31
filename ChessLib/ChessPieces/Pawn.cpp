#include "Pawn.h"
#include "../Chessboard.h"

Pawn::Pawn(Chessboard& chessboard, Team team, char pos)
	: Piece(chessboard, team, pos)
{
}

Piece::Type Pawn::getType() const
{
	return Piece::Type::Pawn;
}

void Pawn::getMoves(std::vector<Move>& moves) const
{
	char moveDirection;
	std::vector<char> captureDirections;
	char maxDistance = getMaxDistance();
	auto king = chessboard.getKing(team);

	if (team == Team::Player1)
	{
		moveDirection = -8;
		captureDirections = { -7, -9 };
	}
	else
	{
		moveDirection = 8;
		captureDirections = { 7, 9 };
	}

	// Generowanie ruchow i promocji
	{
		std::vector<std::pair<char, Piece*>> sBuff;
		chessboard.searchDirection(pos, moveDirection, getMaxDistance(), sBuff);

		char maxDistance = sBuff.size();
		for (int i = 0; i < maxDistance; i++)
		{
			if (!sBuff[i].second)
			{
				Move temp = { pos, sBuff[i].first, pos, sBuff[i].first, Move::Type::Move };
				if (sBuff[i].first / 8 == 0 || sBuff[i].first / 8 == 7)
					temp.type = Move::Type::Promotion;

				moves.push_back(temp);
			}
			else
				break;
		}
	}

	// generowanie zbic i bicia w przelocie
	for (const auto& direction : captureDirections)
	{
		std::vector<std::pair<char, Piece*>> sBuff;
		chessboard.searchDirection(pos, direction, 1, sBuff);

		char maxDistance = sBuff.size();
		for (int i = 0; i < maxDistance; i++)
		{
			// Zwykle bicie
			if (sBuff[i].second)
				if (sBuff[i].second->getTeam() != team)
				{
					Move temp = { pos, sBuff[i].first, sBuff[i].first, sBuff[i].first, Move::Type::Capture };
					moves.push_back(temp);
					continue;
				}

			// bicie w przelocie
			char capturePos = sBuff[i].first - moveDirection;
			char currentRow = pos / 8;
			if (chessboard.getPiece(capturePos))
				if (chessboard.getPiece(capturePos)->getTeam() != team &&
					chessboard.getPiece(capturePos)->getState() == State::FirstMove &&
					chessboard.getPiece(capturePos)->getType() == Piece::Type::Pawn &&
					(currentRow == 3 || currentRow == 4))
				{
					Move temp = { pos, sBuff[i].first, capturePos, capturePos, Move::Type::EnPassant };
					moves.push_back(temp);
				}
		}
	}

	removeIllegalMoves(moves);
}