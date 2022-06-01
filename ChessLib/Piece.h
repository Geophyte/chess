#pragma once
#include <cctype>
#include <cmath>
#include <array>
#include <vector>

class Chessboard;

struct Move
{
	char cStart, cDest;	// startowa i ko�cowa pozycja pionka wykonuj�cego ruch
	char oStart, oDest;	// startowa i ko�cowa pozycja pionka na kt�rego dany ruch b�dzie wywiera� wp�yw
						// np. pozycja zbijanego pionka, pozycja pocz�tkowa i ko�cowa kr�la z kt�rym b�dzie roszada
	enum class Type : char
	{
		Move, Capture, Castling, Promotion, EnPassant
	} type;

	char newFigure; // for en passat move

	bool operator<(const Move& other) const;
};

enum class Team : char
{
	Player1, Player2 // Player1 - pozycja 'na dole', Player2 - pozycja 'na g�rze'
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
		NotMoved,		// pionek nie poruszy� si� od pocz�tku rozgrywki
		FirstMove,		// pionek poruszy� si� pierwszy raz w ostatniej kolejce
		Moved			// pionek si� poruszy�
	};
public:
	Piece(Chessboard& chessboard, Team t, char pos);

	Team getTeam() const;
	State getState() const;
	void setState(State s);

	void saveState();
	void restoreState();

	virtual void onMove(char pos);		// funkcja wywo�yna kiedy pionek si� poruszy
	virtual void onNextTurn();	// funkcja wywo�yna na koniec tury (kiedy obydwaj gracze wykonali ruch)

	operator char();
	bool canMove() const;

	virtual Type getType() const = 0;
	virtual char getPos() const;
	virtual void getMoves(std::vector<Move>& moves) const = 0;
protected:
	int getMaxDistance() const;	// zwraca maksymaln� ilo�� p�l kt�r� mo�e pokona� pionek w jednym ruchu
	void getMoves(const std::vector<char>& directions, std::vector<Move>& moves) const;
	void removeIllegalMoves(std::vector<Move>& moves) const;
protected:
	Chessboard& chessboard;
	const Team team;
	char pos;
	State cState, lState;	// current State i last State
};