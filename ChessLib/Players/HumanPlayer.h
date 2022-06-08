#pragma once
#include "Player.h"
#include <iostream>


/// Klasa reprezentujaca gracza-czlowieka.
/// Pobiera ruchy z konsoli oraz podswietla 
/// wszystkie mozliwe ruchy pionka wybranego przez gracza.
class HumanPlayer : public Player
{
private:
	std::istream& inputStream;
public:
	HumanPlayer(Team team, std::istream& stream = std::cin) : Player(team), inputStream(stream) {}
	virtual Move getMove(const Chessboard& board, const ChessboardPrinter& printer) const;
	virtual Piece::Type getPromotion() const;
};