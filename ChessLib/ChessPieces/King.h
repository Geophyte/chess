#pragma once
#include "../Piece.h"

class King : public Piece
{
public:
	King(Chessboard& chessboard, Team t, char pos);

	virtual Type getType() const override;
	virtual void getMoves(std::vector<Move>& moves) const override;

	bool willIndangereKing(Move move) const;	// sprawdza czy ruch narazi kr�la na niebezpiecze�stwo
	char inCheck() const; // zwraca indeks szachuj�cego pionka lub -1 je�li nie jest szachowany
};