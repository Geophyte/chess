#include "RandomPlayer.h"

RandomPlayer::RandomPlayer(Team team)
	: Player(team), gen(rd())
{
}

Move RandomPlayer::getMove(const Chessboard& board, const ChessboardPrinter& printer) const
{
	std::vector<char> pieces;
	std::vector<char> tempBuff;
	board.getTeamOffsets(team, tempBuff);

	// Odseparuj pionki bez ruchów
	for (const auto& offset : tempBuff)
		if (board.getPiece(offset)->canMove())
			pieces.push_back(offset);

	// Wybierz pionek do gry
	std::uniform_int_distribution<> pieceDistr(0, pieces.size() - 1);
	char pieceOffset = pieces[pieceDistr(gen)];

	// Wybierz losowy ruch
	std::vector<Move> moves;
	board.getPiece(pieceOffset)->getMoves(moves);

	std::uniform_int_distribution<> moveDistr(0, moves.size() - 1);
	char moveOffset = moveDistr(gen);
	Move move = moves[moveOffset];

	// Jeœli ruch to promocja wybieramy rodzaj pionka
	if (move.type == Move::Type::Promotion)
	{
		std::vector<Piece::Type> promotionTypes = { Piece::Type::Rook, Piece::Type::Knight, Piece::Type::Bishop, Piece::Type::Queen };
		std::uniform_int_distribution<> promotiontDistr(0, promotionTypes.size() - 1);
		Piece::Type type = promotionTypes[promotiontDistr(gen)];
		move.newFigure = static_cast<char>(type);
	}


	char fromX = move.cStart % 8 + 'a', fromY = (8 - move.cStart / 8) + '1';
	char toX = move.cDest % 8 + 'a', toY = 8 - (move.cDest / 8) + '1';
	std::cout << fromX << fromY << " " << toX << toY << std::endl;

	return move;
}
