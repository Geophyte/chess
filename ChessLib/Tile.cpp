#include "Tile.h"

Piece* Tile::getPiece() const {
	return currPiece;
}

void Tile::setPiece(Piece* newPiece) {
	currPiece = newPiece;
}

int Tile::getX() const {
	return x;
}

int Tile::getY() const {
	return y;
}

bool Tile::isEmpty() const {
	return currPiece == nullptr;
}

Tile::~Tile() {
	delete currPiece;
}