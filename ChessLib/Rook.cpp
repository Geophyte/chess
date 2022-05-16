#include "Rook.h"
#include "Board.h"

bool Rook::canMoveTo(const Board& board, const Tile& from, const Tile& to) const {
	if (to.getPiece() != nullptr && to.getPiece()->getColour() == this->colour) {
		return false;
	}
	if (board.isClearHorizontal(from, to) || board.isClearVertical(from, to))
		return true;
	return false;
}