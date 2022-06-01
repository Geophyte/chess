#include "HumanPlayer.h"
#include "../Chessboard.h"
#include <algorithm>

Move HumanPlayer::getMove(const Chessboard& board, const ChessboardPrinter& printer) const {
	bool condition = true;
	Move userMove;
	while (condition) {
		printer.clear();
		printer.print(board.getFenString());
		char xFrom, yFrom;
		inputStream >> xFrom >> yFrom;
		char offsetFrom = ('8' - yFrom) * 8 + (xFrom - 'a');
		if (offsetFrom < 0 || offsetFrom > 63)
			continue;
		const Piece* from = board.getPiece(offsetFrom);
		if (!from || from->getTeam() != team)
			continue;
		// show available moves
		printer.clear();
		printer.printMoves(offsetFrom, board);
		// get move from user
		char xTo, yTo;
		inputStream >> xTo;
		// player wants to choose another figure, so start again
		if (xTo < 'a' || xTo > 'h')
			continue;
		inputStream >> yTo;
		char offsetTo = ('8' - yTo) * 8 + (xTo - 'a');
		if (offsetTo < 0 || offsetTo > 63)
			continue;
		const Piece* to = board.getPiece(offsetTo);
		std::vector<Move> moves;
		from->getMoves(moves);
		int i;
		for (i = 0; i < moves.size(); ++i) {
			if (moves[i].cDest == offsetTo) {
				userMove = moves[i];
				condition = false;
				break;
			}
		}
	}
	return userMove;
}

Piece::Type HumanPlayer::getPromotion() const
{
	while (true)
	{
		char fig;
		inputStream >> fig;
		fig = tolower(fig);

		if (fig == 'q' || fig == 'n' || fig == 'r' || fig == 'b')
			return static_cast<Piece::Type>(fig);
	}
}
