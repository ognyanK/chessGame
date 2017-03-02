#ifndef KNIGHT_H
#define KNIGHT_H
#include "Figure.h"

class Knight:public Figure{
public:
	Knight();
	Knight(char);

	void PossibleMoves(Map&, int, int,bool);
	~Knight();
};

#endif //  KNIGHT_H