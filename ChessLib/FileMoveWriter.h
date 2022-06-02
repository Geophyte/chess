#pragma once
#include <fstream>
#include "MoveWriterUtilites.h"

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
		stream << moveWriterUtilities::formateMove(move, board, status);
		stream.close();
	}

	void write(const Move& move, const Chessboard& board, GameStatus status, int moveNumber) {
		std::ofstream stream(filename, std::ios::app);
		stream << (moveNumber != 1 ? "\n" : "");
		stream << moveNumber << ". ";
		stream << moveWriterUtilities::formateMove(move, board, status);
		stream.close();
	}
};