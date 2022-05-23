//#include "HumanPlayer.h"
//#include "Board.h"
//
//Move HumanPlayer::getMove(const Board& board) {
//	char x1, x2;
//	int y1, y2;
//	bool condition = true;
//	Tile *from = nullptr, *to=nullptr;
//	while (condition) {
//		try {
//			inputStream >> x1 >> y1 >> x2 >> y2;
//			from = board.getSquare(x1 - 'a', y1 - 1);
//			to = board.getSquare(x2 - 'a', y2 - 1);
//			condition = false;
//		}
//		catch (std::invalid_argument) {
//			condition = true;
//		}
//	}
//	return Move(from, to);
//}

#include "HumanPlayer.h"
#include "../Chessboard.h"
#include <algorithm>

std::pair<char, char> HumanPlayer::getMove(const Chessboard& board) {
	char xFrom, yFrom, xTo, yTo, offsetFrom, offsetTo;
	bool condition = true;
	while (condition) {
		inputStream >> xFrom >> yFrom >> xTo >> yTo;
		offsetFrom = (yFrom - '1') * 8 + (xFrom - 'a');
		offsetTo = (yTo - '1') * 8 + (xTo - 'a');
		if (!board.canMoveStep(offsetFrom, offsetTo))
			continue;
		if (board[offsetFrom]->getTeam() != team || board[offsetFrom]->getType() == Piece::Type::None)
			continue;
		std::vector<char> moves;
		std::vector<char> captures;
		board[offsetFrom]->getMoves(board, offsetFrom, moves, captures);
		if (std::find(moves.begin(), moves.end(), offsetTo) != moves.end() || std::find(captures.begin(), captures.end(), offsetTo) != captures.end())
			condition = false;
	}
	return std::make_pair(offsetFrom, offsetTo);
}