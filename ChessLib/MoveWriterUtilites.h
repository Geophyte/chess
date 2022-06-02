#pragma once
#include "Piece.h"
#include "GameStatus.h"
#include "Chessboard.h"
#include <string>

namespace moveWriterUtilities {
	std::string formateMove(const Move& move, const Chessboard& board, GameStatus status);
}