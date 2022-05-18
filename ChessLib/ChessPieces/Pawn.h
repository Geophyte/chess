#pragma once
#include "../Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Team team);

	virtual Type getType() const override;
	virtual void getMoveDirections(std::vector<char>& direct) const override;
	virtual void getCaptureDirections(std::vector<char>& direct) const;
private:
	static const std::array<char, 3> directions1;
	static const std::array<char, 3> directions2;
};