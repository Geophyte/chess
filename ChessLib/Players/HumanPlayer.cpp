#include "HumanPlayer.h"
#include "../Chessboard.h"
#include <algorithm>

Move HumanPlayer::getMove(const Chessboard& board, const ChessboardPrinter& printer) {
	bool condition = true;
	Move userMove;
	while (condition) {
		std::string input;
		getline(inputStream, input);
		printer.clear();
		printer.printTeam(this->getTeam(), board);
		if (input.length() == 2 || input.length() == 5 || input.length() == 6) {
			char xFrom, yFrom;
			xFrom = input[0]; yFrom = input[1];
			char offsetFrom = ('8' - yFrom) * 8 + (xFrom - 'a');
			if (offsetFrom < 0 || offsetFrom > 63)
				continue;
			const Piece* from = board.getPiece(offsetFrom);
			if (!from || from->getTeam() != team)
				continue;
			if (input.length() == 2) {
				// show available moves
				printer.clear();
				printer.printMoves(offsetFrom, board);
			}
			else {
				// get move from user
				char xTo = input[3]; char yTo = input[4];
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
				if (i < moves.size() && moves[i].type == Move::Type::Promotion && input.length() == 6) {
					condition = true;
					char newFig = input[5];
					char temp = tolower(newFig);
					if (temp == 'q' || temp == 'n' || temp == 'r' || temp == 'b') {
						userMove.newFigure = newFig;
						condition = false;
					}
				}
			}
		}
	}
	return userMove;
}