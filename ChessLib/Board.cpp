#include "Board.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include <cmath>
#include <stdexcept>

Board::Board() {
	board[0][0] = new Tile(0, 0, new Rook(Colour::White));
	board[0][1] = new Tile(1, 0, new Knight(Colour::White));
	board[0][2] = new Tile(2, 0, new Bishop(Colour::White));
	board[0][3] = new Tile(3, 0, new Queen(Colour::White));
	whiteKingTile = new Tile(4, 0, new King(Colour::White));
	board[0][4] = whiteKingTile;
	board[0][5] = new Tile(5, 0, new Bishop(Colour::White));
	board[0][6] = new Tile(6, 0, new Knight(Colour::White));
	board[0][7] = new Tile(7, 0, new Rook(Colour::White));
	for (int i = 0; i < SIZE; ++i) {
		board[1][i] = new Tile(i, 1, new Pawn(Colour::White));
		board[6][i] = new Tile(i, 6, new Pawn(Colour::Black));
	}
	board[7][0] = new Tile(0, 7, new Rook(Colour::Black));
	board[7][1] = new Tile(1, 7, new Knight(Colour::Black));
	board[7][2] = new Tile(2, 7, new Bishop(Colour::Black));
	blackKingTile = new Tile(4, 7, new King(Colour::Black));
	board[7][4] = blackKingTile;
	board[7][3] = new Tile(3, 7, new Queen(Colour::Black));
	board[7][5] = new Tile(5, 7, new Bishop(Colour::Black));
	board[7][6] = new Tile(6, 7, new Knight(Colour::Black));
	board[7][7] = new Tile(7, 7, new Rook(Colour::Black));
	for (int i = 2; i < SIZE-2; ++i) {
		for (int j = 0; j < SIZE; ++j)
			board[i][j] = new Tile(j, i);
	}
}

Board::~Board() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j)
			delete board[i][j];
	}
}

Tile* Board::getKing(Colour colour) const {
	if (colour == Colour::White)
		return whiteKingTile;
	return blackKingTile;
}

Tile* Board::getSquare(const int x, const int y) const {
	if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
		throw std::invalid_argument("Wrong size");
	return board[y][x];
}

bool Board::isClearHorizontal(const Tile& from, const Tile& to) const {
	int step = 1;
	if (from.getX() > to.getX())
		step = -1;
	if (from.getY() != to.getY())
		return false;
	else {
		for (int i = from.getX() + step; i != to.getX(); i += step) {
			if (!getSquare(i, from.getY())->isEmpty())
				return false;
		}
	}
	return true;
}

bool Board::isClearVertical(const Tile& from, const Tile& to) const {
	int step = 1;
	if (from.getY() > to.getY())
		step = -1;
	if (from.getX() != to.getX())
		return false;
	else {
		for (int i = from.getY() + step; i != to.getY(); i += step) {
			if (!getSquare(from.getX(), i)->isEmpty())
				return false;
		}
	}
	return true;
}

bool Board::isClearDiagonal(const Tile& from, const Tile& to) const {
	int deltaX = to.getX() - from.getX();
	int deltaY = to.getY() - from.getY();
	if (abs(deltaX) != abs(deltaY)) {
		return false;
	}
	int stepX = 1;
	int stepY = 1;
	if (deltaX < 0)
		stepX = -1;
	if (deltaY < 0)
		stepY = -1;
	else {
		for (int i = 1; i < abs(deltaX); ++i) {
			if (!getSquare(from.getX() + (i*stepX), from.getY() + (i*stepY))->isEmpty())
				return false;
		}
	}
	return true;
}