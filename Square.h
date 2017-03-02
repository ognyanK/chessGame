#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "Figure.h"

class Square
{
public:
	Square();
	Square(int, int);
	void printPart(int)const;
	Figure* getFigure();
	Figure* getFigure_s(const std::string*);
	void setFigure(Figure*);
	void delFigure();
private:
	bool squareColor; // 1 white, 0 black
	Figure* fig;
};

#endif // ! SQUARE_H
