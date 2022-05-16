#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Colour colour) : Piece(colour) {}
	virtual ~Pawn() {}
	virtual bool canMoveTo(const Board& board, const Tile& from, const Tile& to) const;
};