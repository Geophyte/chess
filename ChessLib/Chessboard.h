#pragma once
#include "Piece.h"
#include "ChessPieces.h"

#include <string>
#include <array>
#include <vector>
#include <memory>
#include <stdexcept>

class Chessboard
{
	friend class Piece;
public:
	Chessboard(const char* fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

	std::string getFenString() const;	// zwraca aktualne po³o¿enie figur jako FEN string
	void getMoves(char pos, std::vector<char>& moveBuff, std::vector<char>& captureBuff) const;	// zwraca mo¿liwe do wykonania ruchy przez figurê na danej pozycji

	bool canMoveStep(char current, char dest) const;	// sprawdza czy mo¿na przejœæ miêdzy polami bez wychodzenia za planszê i 'teleportacji' na drug¹ stronê
	void makeMove(const char offsetFrom, const char offsetTo);
	void undoMove(const char offsetFrom, const char offsetTo);
	const Piece* operator[](char offset) const;
private:
	std::array<std::unique_ptr<Piece>, 64> chessboard;
	std::unique_ptr<Piece> lastMove;
};