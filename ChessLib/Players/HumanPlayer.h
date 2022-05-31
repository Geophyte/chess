#pragma once
#include "Player.h"
#include <iostream>

class HumanPlayer : public Player
{
private:
	std::istream& inputStream;
public:
	HumanPlayer(bool isWhite, std::istream& stream = std::cin) : Player(isWhite), inputStream(stream) {}
	virtual Move getMove(const Chessboard& board, const ChessboardPrinter& printer);
};