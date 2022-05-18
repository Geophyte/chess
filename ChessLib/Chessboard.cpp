#include "Chessboard.h"

Chessboard::Chessboard(const char* fen)
{
	unsigned tileIndex = 0;
	for (unsigned i = 0; i < strlen(fen); ++i)
	{
		if (isalpha(fen[i]))
		{
			Piece::Team team = isupper(fen[i]) ? Piece::Team::Player1 : Piece::Team::Player2;
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

void Chessboard::getMoves(char row, char column, std::vector<char>& moveBuff, std::vector<char>& captureBuff) const
{
	// Prawdopodobnie zbêdna funkcja

	moveBuff.clear();
	captureBuff.clear();

	if (row < 1 || row > 8)
		throw std::invalid_argument("Row must be in [1-8] range");
	if (column < 'a' || column > 'h')
		throw std::invalid_argument("Column must be in [a-h] range");

	getMoves((8 - row) * 8 + (column - 'a'), moveBuff, captureBuff);
}

void Chessboard::getMoves(char pos, std::vector<char>& moveBuff, std::vector<char>& captureBuff) const
{
	Piece::Type type = chessboard[pos]->getType();
	Piece::Team team = chessboard[pos]->getTeam();
	int maxDistance = getMaxDistance(chessboard[pos].get());

	std::vector<char> moveDirects;

	chessboard[pos]->getMoveDirections(moveDirects);

	if (type == Piece::Type::Pawn)
	{
		std::vector<char> captureDirects;
		dynamic_cast<Pawn*>(chessboard[pos].get())->getCaptureDirections(captureDirects);

		// dodawanie mo¿liwych zbiæ dla pionka
		for (const auto& dircetion : captureDirects)
		{
			char nextPos = pos + dircetion;
			char currentPos = pos;

			if (!canMoveStep(currentPos, nextPos))
				break;
			currentPos = nextPos;

			if (chessboard[currentPos])
				if (chessboard[currentPos]->getTeam() != team)
					captureBuff.push_back(currentPos);

			// TO DO
			// Dodaæ wykrywanie bicia w przelocie
		}
	}

	for (const auto& dircetion : moveDirects)	// wybieramy kierunek wzd³u¿ którego bêdziemy siê poruszaæ
	{
		char nextPos;
		char currentPos = pos;
		for (int i = 0; i < maxDistance; i++)
		{
			nextPos = currentPos + dircetion;

			if (!canMoveStep(currentPos, nextPos))
				break;
			currentPos = nextPos;

			// TO DO
			// dodaæ wykrywanie mo¿liwoœci roszady
			// przeciwdzia³anie szachowaniu
			// sprawdzanie czy ruch ods³ania sojuszniczego króla

			// dodawanie mo¿liwych ruchów
			if (!chessboard[currentPos])
			{
				moveBuff.push_back(currentPos);
				continue;
			}

			// dodawanie mo¿liwych zbiæ
			if (type != Piece::Type::Pawn && chessboard[currentPos]->getTeam() != team)
			{
				captureBuff.push_back(currentPos);
				break;
			}
			else
				break;
		}
	}
}

int Chessboard::getMaxDistance(Piece* piece) const
{
	switch (piece->getType())
	{
	case Piece::Type::Rook:
	case Piece::Type::Bishop:
	case Piece::Type::Queen:
		return 7;
	case Piece::Type::Knight:
	case Piece::Type::King:
		return 1;
	case Piece::Type::Pawn:
		if (piece->getDistance())
			return 1;
		else
			return 2;
	}

	return 0;
}

bool Chessboard::canMoveStep(char current, char dest) const
{
	if (dest < 0 || dest >= 64)
		return false;

	return abs(current % 8 - dest % 8) < 6;
}
