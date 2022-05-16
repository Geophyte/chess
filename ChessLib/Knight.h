#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	explicit Knight(Colour colour) : Piece(colour) {}
	virtual ~Knight() {}
	virtual bool canMoveTo(const Board& board, const Tile& from, const Tile& to) const;
};