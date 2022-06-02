#include "MoveWriterUtilites.h"

std::string moveWriterUtilities::formateMove(const Move& move, const Chessboard& board, GameStatus status) {
	std::string stream = "";
	if (move.type == Move::Type::Castling) {
		if (abs(move.cDest - move.cStart) < abs(move.oDest - move.oStart))
			stream += "0-0-0";
		else
			stream += "0-0";
	}
	else {
		const Piece* to = board.getPiece(move.cDest);
		if (to->getType() != Piece::Type::Pawn && move.promoteFigure == Piece::Type::None) {
			char temp = static_cast<char>(to->getType());
			stream += char(toupper(temp));
		}
		stream += char(move.cStart % 8 + 'a');
		stream += char('8' - move.cStart / 8);
		if (move.type == Move::Type::Capture || move.type == Move::Type::EnPassant)
			stream += 'x';
		else
			stream += '-';
		stream += char(move.cDest % 8 + 'a');
		stream += char('8' - move.cDest / 8);
		if (move.type == Move::Type::EnPassant)
			stream += " e.p.";
		else if (move.promoteFigure != Piece::Type::None) {
			char temp = static_cast<char>(move.promoteFigure);
			stream += '=';
			stream += char(toupper(temp));
		}
	}
	if (status == GameStatus::InCheck)
		stream += '+';
	else if (status == GameStatus::End)
		stream += '#';
	else if (status == GameStatus::Stalemate)
		stream += "\n0.5:0.5";
	stream += "  ";
	return stream;
}