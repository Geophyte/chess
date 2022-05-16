#include "Pawn.h"
#include "Tile.h"
#include "Board.h"
#include <cmath>


bool Pawn::canMoveTo(const Board& board, const Tile& from, const Tile& to) const {
	if (to.getPiece() != nullptr && to.getPiece()->getColour() == this->colour) {
		return false;
	}
	int deltaX = to.getX() - from.getX();
	int deltaY = to.getY() - from.getY();
	if (this->colour == Colour::Black)
		deltaY *= -1;
	if (deltaY == 1 && deltaX == 0)
		return to.isEmpty();
	else if (deltaY == 2 && deltaX == 0 && board.isClearVertical(from, to))
		return isFirstMove;
	else if (deltaY == 1 && abs(deltaX) == 1 && !to.isEmpty())
		return true;
	return false;
}