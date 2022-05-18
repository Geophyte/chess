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
public:
	Chessboard(const char* fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

	std::string getFenString() const;	// zwraca aktualne po³o¿enie figur jako FEN string
	void getMoves(char pos, std::vector<char>& moveBuff, std::vector<char>& captureBuff) const;					// zwraca mo¿liwe do wykonania ruchy przez figurê na danej pozycji
	void getMoves(char row, char column, std::vector<char>& moveBuff, std::vector<char>& captureBuff) const;	// row jest podawane jako cyfra w przedziale [1-8], column to litera w przedziale [a-h]
private:
	int getMaxDistance(Piece* piece) const;	// zwraca maksymaln¹ iloœæ pól któr¹ mo¿e pokonaæ pionek w jednym ruchu
	bool canMoveStep(char current, char dest) const;	// sprawdza czy mo¿na przejœæ miêdzy polami bez wychodzenia za planszê i 'teleportacji' na drug¹ stronê
private:
	std::array<std::unique_ptr<Piece>, 64> chessboard;
};