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

/// Klasa wypisująca aktualny stan planszy do konsoli.
/// Klasa posiada metody 'podświetlające' możliwe do wyboru pionki oraz
/// wizualizuje możliwe do wykonania ruchu przez wybrany pionek.
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

	void print(std::string fen) const;	// ci�g znak�w FEN, du�a litera = player1, ma�a litera = player2
										// p - pionek, r - wie�a, n - skoczek, b - goniec, q - hetman, k - kr�l, / - koniec wiersza, [1-9] - liczba pustych miejsc
	void clear() const;

	void printMoves(char pos, const Chessboard& board) const;
	void printTeam(Team team, const Chessboard& board) const;
private:
	void print(const std::array<std::array<TileInfo, 9>, 9>& info) const;
	void setBackgroundColor(Color color) const;
	void setCharColor(Color color) const;
	void resetColor() const;
	std::array<std::array<TileInfo, 9>, 9> getChessboardTiles(const char* fen) const;
private:
	Color player1, player2, background1, background2;;
};