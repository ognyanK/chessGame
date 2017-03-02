#ifndef QUEEN_H
#define QUEEN_H
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"

class Queen:public Rook
{
public:
	Queen();
	Queen(char);

	void PossibleMoves(Map&, int, int,bool);
	~Queen();
private:
	Bishop* in_terms_of;
};

#endif // QUEEN_H
