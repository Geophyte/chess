#include "HumanPlayer.h"
#include "../Chessboard.h"
#include <algorithm>

Move HumanPlayer::getMove(const Chessboard& board) {
	bool condition = true;
	Move userMove;
	while (condition) {
		char xFrom, yFrom, xTo, yTo;
		inputStream >> xFrom >> yFrom >> xTo >> yTo;
		char offsetFrom = ('8' - yFrom) * 8 + (xFrom - 'a');
		char offsetTo = ('8' - yTo) * 8 + (xTo - 'a');
		if (offsetFrom < 0 || offsetFrom > 63)
			continue;
		if (offsetTo < 0 || offsetTo > 63)
			continue;
		const Piece* from = board.getPiece(offsetFrom);
		const Piece* to = board.getPiece(offsetTo);
		if (!from || from->getTeam() != team)
			continue;
		std::vector<Move> moves;
		from->getMoves(moves);
		int i = -1;
		for (i = 0; i < moves.size(); ++i) {
			if (moves[i].cDest == offsetTo) {
				userMove = moves[i];
				condition = false;
				break;
			}
		}
		if (i != -1 && moves[i].type == Move::Type::Promotion) {
			condition = true;
			char newFig;
			inputStream >> newFig;
			char temp = tolower(newFig);
			if (temp == 'q' || temp == 'n' || temp == 'r' || temp == 'b') {
				userMove.newFigure = newFig;
				condition = false;
			}
		}
		inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return userMove;
}