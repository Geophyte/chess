#include "Chessboard.h"

Chessboard::Chessboard(const char* fen)
	: king1(nullptr), king2(nullptr)
{
	unsigned tileIndex = 0;
	for (unsigned i = 0; i < strlen(fen); ++i)
	{
		if (isalpha(fen[i]))
		{
			Team team = isupper(fen[i]) ? Team::Player1 : Team::Player2;
			switch (tolower(fen[i]))
			{
			case 'p':
				chessboard[tileIndex] = std::make_unique<Pawn>(*this, team, tileIndex);
				break;
			case 'r':
				chessboard[tileIndex] = std::make_unique<Rook>(*this, team, tileIndex);
				break;
			case 'n':
				chessboard[tileIndex] = std::make_unique<Knight>(*this, team, tileIndex);
				break;
			case 'b':
				chessboard[tileIndex] = std::make_unique<Bishop>(*this, team, tileIndex);
				break;
			case 'q':
				chessboard[tileIndex] = std::make_unique<Queen>(*this, team, tileIndex);
				break;
			case 'k':
				chessboard[tileIndex] = std::make_unique<King>(*this, team, tileIndex);
				if (team == Team::Player1)
					king1 = dynamic_cast<King*>(chessboard[tileIndex].get());
				else
					king2 = dynamic_cast<King*>(chessboard[tileIndex].get());
				break;
			}
			++tileIndex;
		}
		else if (isdigit(fen[i]))
			tileIndex += fen[i] - '0';
	}
}

void Chessboard::makeMove(Move move)
{
	chessboard[move.cStart]->saveState();
	chessboard[move.oStart]->saveState();
	chessboard[move.cStart]->onMove(move.cDest);
	chessboard[move.oStart]->onMove(move.oDest);

	switch (move.type)
	{
	case Move::Type::Promotion:
	case Move::Type::Move:
		chessboard[move.cStart].swap(chessboard[move.cDest]);
		break;
	case Move::Type::Capture:
	case Move::Type::EnPassant:
		shadowRealm.reset();
		chessboard[move.oStart].swap(shadowRealm);
		chessboard[move.cStart].swap(chessboard[move.cDest]);
		break;
	case Move::Type::Castling:
		chessboard[move.cStart].swap(chessboard[move.cDest]);
		chessboard[move.oStart].swap(chessboard[move.oDest]);
		break;
	}
}

void Chessboard::undoMove(Move move)
{
	switch (move.type)
	{
	case Move::Type::Promotion:
	case Move::Type::Move:
		chessboard[move.cStart].swap(chessboard[move.cDest]);
		break;
	case Move::Type::Capture:
	case Move::Type::EnPassant:
		chessboard[move.cStart].swap(chessboard[move.cDest]);
		chessboard[move.oStart].swap(shadowRealm);
		shadowRealm.reset();
		break;
	case Move::Type::Castling:
		chessboard[move.cStart].swap(chessboard[move.cDest]);
		chessboard[move.oStart].swap(chessboard[move.oDest]);
		break;
	}

	chessboard[move.cStart]->onMove(move.cStart);
	chessboard[move.oStart]->onMove(move.oStart);
	chessboard[move.cStart]->restoreState();
	chessboard[move.oStart]->restoreState();
}

std::string Chessboard::getFenString() const
{
	std::string result;

	unsigned emptyCounter = 0u;
	for (unsigned i = 0; i < chessboard.size(); ++i)
	{
		if (chessboard[i])
		{
			if (emptyCounter)
			{
				result.push_back(emptyCounter + '0');
				emptyCounter = 0;
			}

			result.push_back(*chessboard[i]);
		}
		else
			++emptyCounter;

		if ((i+1) % 8 == 0)
		{
			if (emptyCounter)
			{
				result.push_back(emptyCounter + '0');
				emptyCounter = 0;
			}

			if(i != chessboard.size() - 1)
				result.push_back('/');
		}
	}
	
	return result;
}

void Chessboard::getMoves(char pos, std::vector<Move>& moves) const
{
	chessboard[pos]->getMoves(moves);
}

void Chessboard::searchDirection(char pos, char direction, std::vector<std::pair<char, Piece*>>& buffer) const
{
	searchDirection(pos, direction, 7, buffer);
}

void Chessboard::searchDirection(char pos, char direction, char max, std::vector<std::pair<char, Piece*>>& buffer) const
{
	char nextPos = pos + direction;
	char destPos = pos;
	for (int i=0; i<max && canMoveStep(destPos, nextPos); i++)
	{
		destPos = nextPos;
		nextPos = destPos + direction;

		buffer.push_back(std::pair<char, Piece*>(destPos, chessboard[destPos].get()));
	}
}

bool Chessboard::canMoveStep(char current, char dest) const
{
	if (dest < 0 || dest >= 64)
		return false;

	return abs(current % 8 - dest % 8) < 6;
}

void Chessboard::getTeamOffsets(Team team, std::vector<char>& offsets) const
{
	for (int i = 0; i < chessboard.size(); i++)
		if (chessboard[i].get())
			if (chessboard[i]->getTeam() == team)
				offsets.push_back(i);
}

const King* Chessboard::getKing(Team team) const
{
	if (team == Team::Player1)
		return king1;
	return king2;
}

const Piece* Chessboard::getPiece(char pos) const
{
	return chessboard[pos].get();
}
