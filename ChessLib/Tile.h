#pragma once
class Piece;

class Tile
{
private:
	int x;
	int y;
	Piece* currPiece;
public:
	Tile(int x, int y) : x(x), y(y), currPiece(nullptr) {}
	Tile(int x, int y, Piece* piece) : x(x), y(y), currPiece(piece) {}
	bool isEmpty() const;
	Piece* getPiece() const;
	void setPiece(Piece* newPiece);
	int getX() const;
	int getY() const;
	~Tile();
};