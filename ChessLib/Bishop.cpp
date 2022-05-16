#include "Bishop.h"
#include "Board.h"

bool Bishop::canMoveTo(const Board& board, const Tile& from, const Tile& to) const {
	if (to.getPiece() != nullptr && to.getPiece()->getColour() == this->colour) {
		return false;
	}
	if (board.isClearDiagonal(from, to))
		return true;
	return false;
}