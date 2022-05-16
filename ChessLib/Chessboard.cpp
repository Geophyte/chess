#include "Chessboard.h"

Chessboard::Chessboard()
	: m_bgColor1(COLOR_WHITE), m_bgColor2(COLOR_BLACK), m_chessboard{}
{
	for (auto& i : m_chessboard)
		for (auto& j : i)
			j = { ' ', COLOR_WHITE };
}

void Chessboard::SetCheckboardColor(Color c1, Color c2)
{
	m_bgColor1 = c1; m_bgColor2 = c2;
}

void Chessboard::SetTile(char column, size_t row, char character, Color color)
{
	m_chessboard[(size_t)column - 'a'][8 - row] = { character, color };
}

void Chessboard::Print()
{
	for (unsigned i = 0; i < m_chessboard.size(); ++i)
	{
		printf("\x1B[0m %u ", 8 - i);
		for (unsigned j = 0; j < m_chessboard[0].size(); ++j)
		{
			if ((i + j) % 2)
				SetBackgroundColor(m_bgColor2);
			else
				SetBackgroundColor(m_bgColor1);

			SetCharacterColor(m_chessboard[j][i].charColor);
			printf(" %c ", m_chessboard[j][i].character);
		}
		printf("\n");
	}
	printf("\x1B[0m   ");
	for (char i = 'a'; i < 'a' + 8; ++i)
		printf(" %c ", i);
	printf("\n\x1B[0m");
}

void Chessboard::SetBackgroundColor(Color c)
{
	switch (c)
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

void Chessboard::SetCharacterColor(Color c)
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
