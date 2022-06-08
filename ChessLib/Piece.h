#pragma once
#include <cctype>
#include <cmath>
#include <array>
#include <vector>

class Chessboard;

struct Move;

enum class Team : char
{
	Player1, Player2 // Player1 - pozycja 'na dole', Player2 - pozycja 'na g�rze'
};

///	Klasa bazowa dla wszystkich pionków.
/// Głównym zadaniem klasy jest generowanie możliwych do wykonania ruchów na
/// podstawie pozycji własnej i innych pionków na szachownicy, które nie są 
/// sprzeczne z regułami gry.
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
	void setPos(char pos);

	void saveState();
	void restoreState();

	virtual void onMove(char pos);		// funkcja wywo�yna kiedy pionek si� poruszy
	virtual void onNextTurn();	// funkcja wywo�yna na koniec tury (kiedy obydwaj gracze wykonali ruch)

	operator char() const;
	bool canMove() const;
	bool canPromote() const;
	bool canPromote(char pos) const;

	virtual Type getType() const = 0;
	virtual char getPos() const;
	virtual void getMoves(std::vector<Move>& moves) const;			// generuje ruchy i usuwa nielegalne ruchy
	virtual void generateMoves(std::vector<Move>& moves) const = 0;	// generuje wszystkie ruchy
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

///	Klasa na podstawie, której pionki wykonują ruch.
//! cStart i cDest oznaczają pozycję startową i końcową pionka wykonującego ruch.
//! oStart i oDest oznaczają pozycję startową i końcową pionka na którego dany ruch wywrze wpływ np. pozycja zbijanego pionka
//! type określa rodzaj ruchu. Rozróżniamy 4 rodzaje ruchu: zwykły ruch, zbicie, roszadę i bicie w przelocie
//! promoteFigure określa na jaką figurę zmieni się pionek po wykonaniu ruchu
///
/// W przypdaku roszady cStart i cDest zawsze odnosi się do króla, a oStart, oDest do wieży
struct Move
{
	char cStart, cDest;
	char oStart, oDest;
	enum class Type : char
	{
		Move, Capture, Castling, EnPassant
	} type;

	Piece::Type promoteFigure = Piece::Type::None;
	bool operator<(const Move& other) const;
};