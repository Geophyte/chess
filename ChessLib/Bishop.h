#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	explicit Bishop(Colour colour) : Piece(colour) {}
	virtual ~Bishop() {}
	virtual bool canMoveTo(const Board& board, const Tile& from, const Tile& to) const;
};