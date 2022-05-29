#pragma once
#include "../Piece.h"

class King : public Piece
{
public:
	King(Chessboard& chessboard, Team t, char pos);

	virtual Type getType() const override;
	virtual void getMoves(std::vector<Move>& moves) const override;

	bool willIndangereKing(Move move) const;	// sprawdza czy ruch narazi króla na niebezpieczeñstwo
	char inCheck() const; // zwraca indeks szachuj¹cego pionka lub -1 jeœli nie jest szachowany
};