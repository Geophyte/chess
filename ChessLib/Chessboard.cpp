#include "Chessboard.h"

Chessboard::Chessboard(const char* fen)
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
				chessboard[tileIndex] = std::make_unique<Pawn>(team);
				break;
			case 'r':
				chessboard[tileIndex] = std::make_unique<Rook>(team);
				break;
			case 'n':
				chessboard[tileIndex] = std::make_unique<Knight>(team);
				break;
			case 'b':
				chessboard[tileIndex] = std::make_unique<Bishop>(team);
				break;
			case 'q':
				chessboard[tileIndex] = std::make_unique<Queen>(team);
				break;
			case 'k':
				chessboard[tileIndex] = std::make_unique<King>(team);
				break;
			}
			++tileIndex;
		}
		else if (isdigit(fen[i]))
			tileIndex += fen[i] - '0';
	}
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

void Chessboard::getMoves(char pos, std::vector<char>& moveBuff, std::vector<char>& captureBuff) const
{
	chessboard[pos]->getMoves(*this, pos, moveBuff, captureBuff);
}

bool Chessboard::canMoveStep(char current, char dest) const
{
	if (dest < 0 || dest >= 64)
		return false;

	return abs(current % 8 - dest % 8) < 6;
}

const Piece* Chessboard::operator[](char offset) const
{
	return chessboard[offset].get();
}
