#pragma once
#include "Chessboard.h"

#include <algorithm>
#include <iostream>
#include <array>

#define COLOR_BLACK		ChessboardPrinter::Color::Black
#define COLOR_RED		ChessboardPrinter::Color::Red
#define COLOR_GREEN		ChessboardPrinter::Color::Green
#define COLOR_YELLOW	ChessboardPrinter::Color::Yellow
#define COLOR_BLUE		ChessboardPrinter::Color::Blue
#define COLOR_MAGENTA	ChessboardPrinter::Color::Magenta
#define COLOR_CYAN		ChessboardPrinter::Color::Cyan
#define COLOR_WHITE		ChessboardPrinter::Color::White

class ChessboardPrinter
{
public:
	enum class Color : char
	{
		Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
	};
	struct TileInfo
	{
		char character;
		Color charColor;
		Color bgColor;
	};
public:
	ChessboardPrinter(Color player1 = COLOR_BLUE, Color player2 = COLOR_RED, Color background1 = COLOR_WHITE, Color background2 = COLOR_BLACK);

	void print(const char* fen) const;	// ci¹g znaków FEN, du¿a litera = player1, ma³a litera = player2
	void print(std::string fen) const;	// p - pionek, r - wie¿a, n - skoczek, b - goniec, q - hetman, k - król, / - koniec wiersza, [1-9] - liczba pustych miejsc
	void refreshScreen(std::string fen) const;
	void printMoves(char pos, const Chessboard& board) const;
private:
	void setBackgroundColor(Color color) const;
	void setBackgroundColor(unsigned tile) const;
	void setPieceColor(bool isPlayer1) const;
	void resetColor() const;
private:
	Color player1, player2, background1, background2;;
};