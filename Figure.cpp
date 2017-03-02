#include "Figure.h"
#include "Pond.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <vector>
#include "Map.h"
#include <cmath>

Figure::Figure()
{
}
Figure::Figure(char col,char name)
{
	color = col;
	figureName = name;
	castle = true;
}

Figure* Figure::VirtualConstructor(int i,int j) {
	if (i == 1)return new Pond('B');
	else if (i == 6)return new Pond('W');
	else if (i == 0) {
		if (j == 0 || j == 7)return new Rook('B');
		else if (j == 1 || j == 6) return new Knight('B');
		else if (j == 2 || j == 5) return new Bishop('B');
		else if (j == 3) return new Queen('B');
		else return new King('B');
	}
	else if (i == 7) {
		if (j == 0 || j == 7)return new Rook('W');
		else if (j == 1 || j == 6) return new Knight('W');
		else if (j == 2 || j == 5) return new Bishop('W');
		else if (j == 3) return new Queen('W');
		else return new King('W');
	}

	else return new Pond('R');
}

std::ostream& operator<<(std::ostream& str, const Figure& obj) {
	str << obj.color << obj.figureName;
	return str;
}

Figure::~Figure()
{
}

void Figure::PossibleMoves(Map&, int, int,bool){}

void Figure::Move(Map& board, int torow, int tocol, int prevrow, int prevcol)throw(int) {
	Square* temp = board.IndexSquare(torow, tocol);
	Square* prev = board.IndexSquare(prevrow, prevcol);

		if (prev->getFigure()->figureName == 'K') {
			if (abs(tocol - prevcol) > 1) {
				if (tocol > prevcol) {    //small castle
					board.IndexSquare(torow, tocol -1)->setFigure(board.IndexSquare(torow, tocol+1)->getFigure());//rook
					board.IndexSquare(torow, tocol + 1)->delFigure();
				}
				else {					//large castle
					board.IndexSquare(torow, tocol + 1)->setFigure(board.IndexSquare(torow, tocol -2)->getFigure());//rook
					board.IndexSquare(torow, tocol -2)->delFigure();
				}
			}
		}

	bool flag = true;
	for (std::vector< Square* >::iterator it = moves.begin();
		it != moves.end(); it++)
	{
		if (*it == temp) {
			temp->setFigure(prev->getFigure());
			prev->delFigure();
			flag = false;
			break;
		}
	}
	if (flag)throw 50; // invalid move;
	
	if (temp->getFigure()->figureName == 'K' || temp->getFigure()->figureName == 'R')temp->getFigure()->castle = false;
}