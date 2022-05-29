#include "HumanPlayer.h"
#include "../Chessboard.h"
#include <algorithm>

std::pair<char, char> HumanPlayer::getMove(const Chessboard& board) {
	char xFrom, yFrom, xTo, yTo, offsetFrom, offsetTo;
	//bool condition = true;
	//while (condition) {
	//	inputStream >> xFrom >> yFrom >> xTo >> yTo;
	//	offsetFrom = (yFrom - '1') * 8 + (xFrom - 'a');
	//	offsetTo = (yTo - '1') * 8 + (xTo - 'a');
	//	if (!board.canMoveStep(offsetFrom, offsetTo))
	//		continue;
	//	if (!board[offsetFrom] || board[offsetFrom]->getTeam() != team)
	//		continue;
	//	std::vector<char> moves;
	//	std::vector<char> captures;
	//	board[offsetFrom]->getMoves(board, offsetFrom, moves, captures);
	//	if (std::find(moves.begin(), moves.end(), offsetTo) != moves.end() || std::find(captures.begin(), captures.end(), offsetTo) != captures.end())
	//		condition = false;
	//}
	return std::make_pair(offsetFrom, offsetTo);
}