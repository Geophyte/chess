#pragma once
#include <cctype>
#include <cmath>
#include <array>
#include <vector>

extern class Chessboard;

class Piece
{
public:
	enum class Type : char
	{
		None = ' ', King = 'k', Queen = 'q', Bishop = 'b', Knight = 'n', Rook = 'r', Pawn = 'p'
	};
	enum class Team : char
	{
		Player1, Player2 // Player1 - pozycja 'na dole', Player2 - pozycja 'na górze'
	};
public:
	Piece(Team t);

	Team getTeam() const;
	char getLastDistance() const;

	void onMove(char dist);

	operator char();

	virtual Type getType() const = 0;
	virtual void getMoves(const Chessboard& chessboard, char pos, std::vector<char>& moves, std::vector<char>& captures) const = 0;
protected:
	int getMaxDistance(Type type) const;	// zwraca maksymaln¹ iloœæ pól któr¹ mo¿e pokonaæ pionek w jednym ruchu
protected:
	char lastDistance;	// iloœæ pól przebyta przez pionka w ostatniej kolejce
	const Team team;
};