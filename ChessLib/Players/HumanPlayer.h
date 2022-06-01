#pragma once
#include "Player.h"
#include <iostream>

class HumanPlayer : public Player
{
private:
	std::istream& inputStream;
public:
	HumanPlayer(Team team, std::istream& stream = std::cin) : Player(team), inputStream(stream) {}
	virtual Move getMove(const Chessboard& board, const ChessboardPrinter& printer) const;
};