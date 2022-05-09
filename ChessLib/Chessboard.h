#pragma once
#include <iostream>
#include <array>

enum class Color : char
{ 
	Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
};

class Chessboard
{
public:
	struct TileInfo
	{
		char character;
		Color charColor;
	};
public:
	Chessboard();

	void SetCheckboardColor(Color c1, Color c2);
	void SetTile(char column, size_t row, char character, Color color);

	void Print();
private:
	void SetBackgroundColor(Color c);
	void SetCharacterColor(Color c);
private:
	Color m_bgColor1, m_bgColor2;
	std::array<std::array<TileInfo, 8u>, 8u> m_chessboard;
};

#define COLOR_BLACK		Color::Black
#define COLOR_RED		Color::Red
#define COLOR_GREEN		Color::Green
#define COLOR_YELLOW	Color::Yellow
#define COLOR_BLUE		Color::Blue
#define COLOR_MAGENTA	Color::Magenta
#define COLOR_CYAN		Color::Cyan
#define COLOR_WHITE		Color::White