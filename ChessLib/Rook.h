#pragma once
#include "Piece.h"
#include "Tile.h"

class Rook : public Piece
{
public:
	explicit Rook(Colour colour) : Piece(colour) {}
	virtual ~Rook() {}
	virtual bool canMoveTo(const Board& board, const Tile& from, const Tile& to) const;
};