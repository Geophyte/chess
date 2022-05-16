#pragma once
#include "Tile.h"
#include "Piece.h"

class Board
{
public:
	static const int SIZE = 8;
private:
	Tile* whiteKingTile;
	Tile* blackKingTile;
	Tile* board[SIZE][SIZE];
public:
	Board();
	~Board();
	Tile* getKing(Colour colour) const;
	Tile* getSquare(const int x, const int y) const;
	bool isClearVertical(const Tile& from, const Tile& to) const;
	bool isClearHorizontal(const Tile& from, const Tile& to) const;
	bool isClearDiagonal(const Tile& from, const Tile& to) const;
};