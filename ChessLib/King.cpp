#include "King.h"
#include "Tile.h"
#include "Board.h"
#include <cmath>

bool King::canMoveTo(const Board& board, const Tile& from, const Tile& to) const {
	if (to.getPiece() != nullptr && to.getPiece()->getColour() == this->colour) {
		return false;
	}
	int deltaX = abs(to.getX() - from.getX());
	int deltaY = abs(to.getY() - from.getY());
	if (deltaX <= 1 && deltaY <= 1)
		return true;
	return false;
}