#ifndef BISHOP_H
#define BISHOP_H
#include "Figure.h"

class Bishop:public Figure
{
public:
	Bishop();
	Bishop(char);

	friend class Queen;
	void PossibleMoves(Map&, int, int,bool);
	~Bishop();
};

#endif // !BISHOP_H