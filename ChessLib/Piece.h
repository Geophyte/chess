#pragma once
#include "Tile.h"

enum class Colour {
	White, Black
};
class Board;

class Piece
{
protected:
	bool killed = false;
	bool isFirstMove = true;
	Colour colour;
public:
	explicit Piece(Colour c) : colour(c) {}
	Colour getColour() const { return colour; }
	bool isKilled() const { return killed; }
	void setFirstMove(bool f) { isFirstMove = f; }
	void setKilled(bool k) { killed = k; }
	virtual bool canMoveTo(const Board& board, const Tile& from, const Tile& to) const = 0;
	virtual ~Piece() {}
};