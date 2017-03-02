#ifndef MAP_H
#define MAP_H
#include "Square.h"
#include <vector>
#include <iostream>

class Map
{
private:
	const unsigned WIDTH = 8;
	const unsigned HEIGHT = 8;
public:
	Map();
	void PrintMap()const;
	Square* IndexSquare(int, int);
	bool in_bounds(int)const;
private:
	void printBorderDown()const;
	void InitMap();
	void FillWithSquares();
	Square*** map;
};

#endif // ! MAP_H
