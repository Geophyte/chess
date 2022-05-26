//#pragma once
//#include "Player.h"
//#include <iostream>
//
//class HumanPlayer : public Player
//{
//private:
//	std::istream& inputStream;
//public:
//	HumanPlayer(Colour colour, std::istream& stream = std::cin) : Player(colour), inputStream(stream) {}
//	virtual Move getMove(const Board& board);
//};
#pragma once
#include "Player.h"
#include <iostream>

class HumanPlayer : public Player
{
private:
	std::istream& inputStream;
public:
	HumanPlayer(bool isWhite, std::istream& stream = std::cin) : Player(isWhite), inputStream(stream) {}
	virtual std::pair<char, char> getMove(const Chessboard& board);
};