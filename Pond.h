#ifndef POND_H
#define POND_H
#include "Figure.h"

class Pond:public Figure{
public:
	Pond();
	Pond(char);

	void PossibleMoves(Map&, int, int,bool);
	~Pond();
};
#endif //  POND_H
