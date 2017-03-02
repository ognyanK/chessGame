#ifndef KING_H
#define KING_H
#include "Figure.h"


class King:public Figure
{
public:
	King();
	King(char);
	void ExamineCastlePossibilities(Map&, int, int);
	void PossibleMoves(Map&, int, int,bool);
	~King();
};

#endif // KING_H
