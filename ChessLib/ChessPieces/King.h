#pragma once
#include "../Piece.h"

class King : public Piece
{
public:
	King(Chessboard& chessboard, Team t, char pos);

	virtual Type getType() const override;
	void generateMoves(std::vector<Move>& moves) const override;

	bool willIndangereKing(const Move& move) const;	// sprawdza czy ruch narazi kr�la na niebezpiecze�stwo
	char inCheck() const; // zwraca indeks szachuj�cego pionka lub -1 je�li nie jest szachowany

	void getCastling(std::vector<Move>& moves) const;	// zwraca ruch roszady
};