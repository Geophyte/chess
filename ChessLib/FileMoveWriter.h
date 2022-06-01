#pragma once
#include "Piece.h"
#include <fstream>
#include "GameStatus.h"

class FileMoveWriter
{
private:
	std::string filename;
public:
	explicit FileMoveWriter(std::string filename = "Moves.txt") : filename(filename) {
		// create file or clear it (if it exists)
		std::ofstream stream(filename);
		stream.close();
	}
	std::string getFilename() const { return filename; }
	void write(const Move& move, const Chessboard& board, GameStatus status) {
		std::ofstream stream(filename, std::ios::app);
		if (move.type == Move::Type::Castling) {
			if (abs(move.cDest - move.cStart) < abs(move.oDest - move.oStart))
				stream << "0-0-0";
			else
				stream << "0-0";
		}
		else {
			const Piece* to = board.getPiece(move.cDest);
			if (to->getType() != Piece::Type::Pawn && move.promoteFigure == Piece::Type::None) {
				char temp = static_cast<char>(to->getType());
				stream << char(toupper(temp));
			}
			stream << char(move.cStart % 8 + 'a') << char('8' - move.cStart / 8);
			if (move.type == Move::Type::Capture || move.type == Move::Type::EnPassant)
				stream << 'x';
			else
				stream << '-';
			stream << char(move.cDest % 8 + 'a') << char('8' - move.cDest / 8);
			if (move.type == Move::Type::EnPassant)
				stream << " e.p.";
			else if (move.promoteFigure != Piece::Type::None) {
				char temp = static_cast<char>(move.promoteFigure);
				stream << '=' << char(toupper(temp));
			}
		}
		if (status == GameStatus::InCheck)
			stream << '+';
		else if (status == GameStatus::End)
			stream << '#';
		else if (status == GameStatus::Stalemate)
			stream << "\n0.5:0.5";
		stream << "  ";
		stream.close();
	}

	void write(const Move& move, const Chessboard& board, GameStatus status, int moveNumber) {
		std::ofstream stream(filename, std::ios::app);
		stream << (moveNumber != 1 ? "\n" : "");
		stream << moveNumber << ". ";
		stream.close();
		write(move, board, status);
	}
};