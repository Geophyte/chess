//#pragma once
//#include "Piece.h"
//#include "Move.h"
//
//
//class Player
//{
//protected:
//	Colour colour;
//public:
//	Player(Colour colour) : colour(colour) {}
//	Colour getColour() const { return colour; }
//	virtual Move getMove(const Board& board) = 0;
//};
#pragma once
#include "../Chessboard.h"


class Player
{
protected:
	Team team;
public:
	Player(bool isWhite) { team = isWhite ? Team::Player1 : Team::Player2; }
	Team getTeam() const { return team; }
	virtual std::pair<char, char> getMove(const Chessboard& board) = 0;
};