#include "Queen.h"
#include "Board.h"
#include <cmath>

bool Queen::canMoveTo(const Board& board, const Tile& from, const Tile& to) const {
	if (to.getPiece() != nullptr && to.getPiece()->getColour() == this->colour) {
		return false;
	}
	if (board.isClearDiagonal(from, to) || board.isClearHorizontal(from, to) || board.isClearVertical(from, to))
		return true;
	return false;
}