#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	explicit Queen(Colour colour) : Piece(colour) {}
	virtual ~Queen() {}
	virtual bool canMoveTo(const Board& board, const Tile& from, const Tile& to) const;
};