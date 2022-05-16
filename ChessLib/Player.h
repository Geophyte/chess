#pragma once
#include "Piece.h"
#include "Move.h"


class Player
{
protected:
	Colour colour;
public:
	Player(Colour colour) : colour(colour) {}
	Colour getColour() const { return colour; }
	virtual Move getMove(const Board& board) = 0;
};