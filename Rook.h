#ifndef ROOK_H
#define ROOK_H
#include "Figure.h"

class Rook:public Figure
{
public:
	Rook();
	Rook(char);
	Rook(char,char);

	void PossibleMoves(Map&, int, int,bool);
	~Rook();
};

#endif  //ROOK_H
