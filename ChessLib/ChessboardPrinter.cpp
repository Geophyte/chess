#include "ChessboardPrinter.h"

ChessboardPrinter::ChessboardPrinter(Color player1, Color player2, Color background1, Color background2)
	: player1(player1), player2(player2), background1(background1), background2(background2)
{
}

void ChessboardPrinter::print(std::string fen) const
{
	auto info = getChessboardTiles(fen.c_str());
	print(info);
}

void ChessboardPrinter::clear() const
{
	system("cls");
}

void ChessboardPrinter::printMoves(char pos, const Chessboard& board) const
{
	std::string fen = board.getFenString();
	std::vector<Move> buff;
	board.getMoves(pos, buff);

	auto info = getChessboardTiles(fen.c_str());
	for (const auto& move : buff)
	{
		switch (move.type)
		{
		case Move::Type::Move:
			info[move.cDest / 8][(size_t)move.cDest % 8 + 1].bgColor = COLOR_GREEN;
			break;
		case Move::Type::Capture:
			info[move.cDest / 8][(size_t)move.cDest % 8 + 1].bgColor = COLOR_YELLOW;
			break;
		case Move::Type::Castling:
			info[move.cStart / 8][(size_t)move.cStart % 8 + 1].bgColor = COLOR_CYAN;
			info[move.cDest / 8][(size_t)move.cDest % 8 + 1].bgColor = COLOR_MAGENTA;
			info[move.oStart / 8][(size_t)move.oStart % 8 + 1].bgColor = COLOR_CYAN;
			info[move.oDest / 8][(size_t)move.oDest % 8 + 1].bgColor = COLOR_MAGENTA;
			break;
		case Move::Type::EnPassant:
			info[move.cDest / 8][(size_t)move.cDest % 8 + 1].bgColor = COLOR_MAGENTA;
			info[move.oStart / 8][(size_t)move.oStart % 8 + 1].bgColor = COLOR_YELLOW;
			break;
		}
	}

	print(info);
}

void ChessboardPrinter::printTeam(Team team, const Chessboard& board) const
{
	std::string fen = board.getFenString();
	auto info = getChessboardTiles(fen.c_str());

	std::vector<char> offsets;
	board.getTeamOffsets(team, offsets);
	for (const auto& i : offsets)
		info[i / 8][(size_t)i % 8 + 1].bgColor = COLOR_GREEN;

	print(info);
}

void ChessboardPrinter::print(const std::array<std::array<TileInfo, 9>, 9>& info) const
{
	for (const auto& row : info)
	{
		for (const auto& tile : row)
		{
			setCharColor(tile.charColor);
			setBackgroundColor(tile.bgColor);
			printf(" %c ", tile.character);
		}
		resetColor();
		printf("\n");
	}
	resetColor();
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

void ChessboardPrinter::setCharColor(Color c) const
{
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

std::array<std::array<ChessboardPrinter::TileInfo, 9>, 9> ChessboardPrinter::getChessboardTiles(const char* fen) const
{
	std::string chars = "";
	for (int i = 0; i < strlen(fen); i++)
	{
		if (isalpha(fen[i]))
			chars += fen[i];
		if (isdigit(fen[i]))
			for (int j = 0; j < fen[i] - '0'; j++)
				chars += ' ';
	}

	std::array<std::array<TileInfo, 9>, 9> arr = {};
	for (size_t i = 0; i < 8; i++)
	{
		arr[i][0].character = '8' - i;
		arr[i][0].charColor = COLOR_WHITE;
		arr[i][0].bgColor = COLOR_BLACK;

		for (size_t j = 0; j < 8; j++)
		{
			char current = chars[j + i * 8];
			arr[i][j + 1].character = tolower(current);
			arr[i][j + 1].charColor = islower(current) ? player2 : player1;
			arr[i][j + 1].bgColor = (i + j) % 2 ? background1 : background2;
		}
	}
	arr[8][0].character = ' ';
	for (size_t i = 1; i < 9; i++)
	{
		arr[8][i].character = 'a' - 1 + i;
		arr[8][i].charColor = COLOR_WHITE;
		arr[8][i].bgColor = COLOR_BLACK;
	}
	return arr;
}
