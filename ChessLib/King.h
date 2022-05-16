#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	explicit King(Colour colour) : Piece(colour) {}
	virtual ~King() {}
	virtual bool canMoveTo(const Board& board, const Tile& from, const Tile& to) const;
};