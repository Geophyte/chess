#pragma once
#include "Tile.h"

struct Move
{
	Tile* from;
	Tile* to;
	Move(Tile* from, Tile* to) : from(from), to(to) {}
};