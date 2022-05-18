#pragma once
#include <cctype>
#include <cmath>
#include <array>
#include <vector>

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
	Piece(Team t)
		: distance(0), team(t)
	{}

	Team getTeam() const { return team; }
	char getDistance() const { return distance; }

	void onMove(char dist) { distance = dist; }

	operator char() 
	{ 
		char temp = static_cast<char>(getType());
		
		if (team == Team::Player1)
			temp = toupper(temp);

		return temp;
	}

	virtual Type getType() const = 0;
	virtual void getMoveDirections(std::vector<char>& direct) const = 0;
protected:
	char distance;	// iloœæ pól przebyta przez pionka w ostatniej kolejsce
	const Team team;
};