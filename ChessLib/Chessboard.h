#pragma once
#include "Piece.h"
#include "ChessPieces.h"

#include <string>
#include <array>
#include <vector>
#include <memory>
#include <utility>
#include <stdexcept>

class Chessboard
{
	friend class Piece;
public:
	Chessboard(const char* fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

	void makeMove(Move move);
	void undoMove(Move move);
	void searchDirection(char pos, char direction, std::vector<std::pair<char, Piece*>>& buffer) const;						// Przeszukuje planszê w danym kierunku do krawêdzi planszy
	void searchDirection(char pos, char direction, char max, std::vector<std::pair<char, Piece*>>& buffer) const;	// Przeszukuje planszê w danym kierunku do krawêdzi planszy ograniczaj¹c siê do max pól

	bool canMoveStep(char current, char dest) const;	// sprawdza czy mo¿na przejœæ miêdzy polami bez wychodzenia za planszê

	std::string getFenString() const;	// zwraca aktualne po³o¿enie figur jako FEN string
	void getMoves(char pos, std::vector<Move>& moves) const;	// zwraca mo¿liwe do wykonania ruchy przez figurê na danej pozycji
	void getTeamOffsets(Team team, std::vector<char>& offsets) const;
	void switchPromotion(char position, char newFigure);
	King* getKing(Team team) const;
	Piece* getPiece(char pos) const;
private:
	King *king1, *king2;
	std::unique_ptr<Piece> shadowRealm;
	std::array<std::unique_ptr<Piece>, 64> chessboard;
};