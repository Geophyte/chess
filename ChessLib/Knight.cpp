#include "Knight.h"
#include "Board.h"
#include <cmath>

bool Knight::canMoveTo(const Board& board, const Tile& from, const Tile& to) const {
	if (to.getPiece() != nullptr && to.getPiece()->getColour() == this->colour) {
		return false;
	}
	int deltaX = abs(to.getX() - from.getX());
	int deltaY = abs(to.getY() - from.getY());
	if (deltaX == 1 && deltaY == 2)
		return true;
	if (deltaX == 2 && deltaY == 1)
		return true;
	return false;
}