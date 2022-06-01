#pragma once
#include <cctype>
#include <cmath>
#include <array>
#include <vector>

class Chessboard;

struct Move
{
	char cStart, cDest;	// startowa i koñcowa pozycja pionka wykonuj¹cego ruch
	char oStart, oDest;	// startowa i koñcowa pozycja pionka na którego dany ruch bêdzie wywiera³ wp³yw
						// np. pozycja zbijanego pionka, pozycja pocz¹tkowa i koñcowa króla z którym bêdzie roszada
	enum class Type : char
	{
		Move, Capture, Castling, Promotion, EnPassant
	} type;

	char newFigure; // for en passat move

	bool operator<(const Move& other) const;
};

enum class Team : char
{
	Player1, Player2 // Player1 - pozycja 'na dole', Player2 - pozycja 'na górze'
};

class Piece
{
public:
	enum class Type : char
	{
		None = ' ', King = 'k', Queen = 'q', Bishop = 'b', Knight = 'n', Rook = 'r', Pawn = 'p'
	};
	enum class State : char
	{
		NotMoved,		// pionek nie poruszy³ siê od pocz¹tku rozgrywki
		FirstMove,		// pionek poruszy³ siê pierwszy raz w ostatniej kolejce
		Moved			// pionek siê poruszy³
	};
public:
	Piece(Chessboard& chessboard, Team t, char pos);

	Team getTeam() const;
	State getState() const;
	void setState(State s);

	void saveState();
	void restoreState();

	virtual void onMove(char pos);		// funkcja wywo³yna kiedy pionek siê poruszy
	virtual void onNextTurn();	// funkcja wywo³yna na koniec tury (kiedy obydwaj gracze wykonali ruch)

	operator char();
	bool canMove() const;

	virtual Type getType() const = 0;
	virtual char getPos() const;
	virtual void getMoves(std::vector<Move>& moves) const = 0;
protected:
	int getMaxDistance() const;	// zwraca maksymaln¹ iloœæ pól któr¹ mo¿e pokonaæ pionek w jednym ruchu
	void getMoves(const std::vector<char>& directions, std::vector<Move>& moves) const;
	void removeIllegalMoves(std::vector<Move>& moves) const;
protected:
	Chessboard& chessboard;
	const Team team;
	char pos;
	State cState, lState;	// current State i last State
};