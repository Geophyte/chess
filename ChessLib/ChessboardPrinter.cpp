#include "ChessboardPrinter.h"

ChessboardPrinter::ChessboardPrinter(Color player1, Color player2, Color background1, Color background2)
	: player1(player1), player2(player2), background1(background1), background2(background2)
{
}

void ChessboardPrinter::print(const char* fen) const
{
	unsigned tileIndex = 0;
	for (unsigned i = 0; i < strlen(fen); ++i)
	{
		if (fen[i] == '/')
			printf("\n");
		else if (tileIndex % 8 == 0)
			printf(" %u ", tileIndex / 8u + 1u);

		if (isalpha(fen[i]))
		{
			setBackgroundColor(tileIndex);
			setPieceColor(isupper(fen[i]));

			printf(" %c ", tolower(fen[i]));
			++tileIndex;
		}
		if (isdigit(fen[i]))
			for (unsigned n = 0; n < fen[i] - '0'; ++n)
			{
				setBackgroundColor(tileIndex);

				printf("   ");
				++tileIndex;
			}
		resetColor();
	}
	printf("\n   ");
	for (char i = 'a'; i < 'a' + 8; ++i)
		printf(" %c ", i);
	printf("\n");
}

void ChessboardPrinter::print(std::string fen) const
{
	print(fen.c_str());
}

void ChessboardPrinter::printMoves(char pos, const Chessboard& board) const
{
	std::string fen = board.getFenString();
	std::vector<char> moves, captures;
	board.getMoves(pos, moves, captures);

	std::sort(moves.begin(), moves.end());
	std::sort(captures.begin(), captures.end());

	char tileIndex = 0;
	for (const auto& i : fen)
	{
		if (i == '/')
			printf("\n");
		else if (tileIndex % 8 == 0)
			printf(" %u ", tileIndex / 8u + 1u);

		if (isalpha(i))
		{
			if(std::find(moves.begin(), moves.end(), tileIndex) != moves.end())
				setBackgroundColor(COLOR_GREEN);
			else if (std::find(captures.begin(), captures.end(), tileIndex) != captures.end())
				setBackgroundColor(COLOR_YELLOW);
			else
				setBackgroundColor(tileIndex);
			setPieceColor(isupper(i));

			printf(" %c ", tolower(i));
			++tileIndex;
		}
		if (isdigit(i))
			for (unsigned n = 0; n < i - '0'; ++n)
			{
				if (std::find(moves.begin(), moves.end(), tileIndex) != moves.end())
					setBackgroundColor(COLOR_GREEN);
				else if (std::find(captures.begin(), captures.end(), tileIndex) != captures.end())
					setBackgroundColor(COLOR_YELLOW);
				else
					setBackgroundColor(tileIndex);

				printf("   ");
				++tileIndex;
			}
		resetColor();
	}
	printf("\n   ");
	for (char i = 'a'; i < 'a' + 8; ++i)
		printf(" %c ", i);
	printf("\n");
}

void ChessboardPrinter::setBackgroundColor(Color color) const
{
	switch (color)
	{
	case COLOR_BLACK:
		printf("\x1B[40m");
		break;
	case COLOR_RED:
		printf("\x1B[41m");
		break;
	case COLOR_GREEN:
		printf("\x1B[42m");
		break;
	case COLOR_YELLOW:
		printf("\x1B[43m");
		break;
	case COLOR_BLUE:
		printf("\x1B[44m");
		break;
	case COLOR_MAGENTA:
		printf("\x1B[45m");
		break;
	case COLOR_CYAN:
		printf("\x1B[46m");
		break;
	case COLOR_WHITE:
		printf("\x1B[47m");
		break;
	}
}

void ChessboardPrinter::setBackgroundColor(unsigned tile) const
{
	Color c = (tile / 8 + tile) % 2 ? background1 : background2;
	setBackgroundColor(c);
}

void ChessboardPrinter::setPieceColor(bool isPlayer1) const
{
	Color c = isPlayer1 ? player1 : player2;

	switch (c)
	{
	case COLOR_BLACK:
		printf("\x1B[30m");
		break;
	case COLOR_RED:
		printf("\x1B[31m");
		break;
	case COLOR_GREEN:
		printf("\x1B[32m");
		break;
	case COLOR_YELLOW:
		printf("\x1B[33m");
		break;
	case COLOR_BLUE:
		printf("\x1B[34m");
		break;
	case COLOR_MAGENTA:
		printf("\x1B[35m");
		break;
	case COLOR_CYAN:
		printf("\x1B[36m");
		break;
	case COLOR_WHITE:
		printf("\x1B[37m");
		break;
	}
}

void ChessboardPrinter::resetColor() const
{
	printf("\u001b[0m");
}
