#include "HumanPlayer.h"
#include "Board.h"

Move HumanPlayer::getMove(const Board& board) {
	char x1, x2;
	int y1, y2;
	bool condition = true;
	Tile *from = nullptr, *to=nullptr;
	while (condition) {
		try {
			inputStream >> x1 >> y1 >> x2 >> y2;
			from = board.getSquare(x1 - 'a', y1 - 1);
			to = board.getSquare(x2 - 'a', y2 - 1);
			condition = false;
		}
		catch (std::invalid_argument) {
			condition = true;
		}
	}
	return Move(from, to);
}