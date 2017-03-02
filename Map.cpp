#include "Map.h"


Map::Map()
{
	InitMap();
	FillWithSquares();
}

void Map::InitMap() {
	map = new Square**[HEIGHT];
	for (unsigned i = 0; i < HEIGHT; i++)
	{
		map[i] = new Square*[WIDTH];
	}
}

void Map::FillWithSquares() {
	for (unsigned i = 0; i < HEIGHT; i++) {
		for (unsigned j = 0; j < WIDTH; j++) {
			map[i][j] = new Square(i, j);
		}
	}
}

void Map::PrintMap() const{
	for (unsigned i = 0; i < HEIGHT; i++) {
		int part = 1;
		std::cout << "     |";
		for (unsigned j = 0; j < WIDTH; j++) {
			map[i][j]->printPart(part);
		}
		part++;
		std::cout << '|' << std::endl;
		std::cout << "  " << i + 1 << "  |" ;
		for (unsigned j = 0; j < WIDTH; j++) {
			map[i][j]->printPart(part);
		}
		part--;
		std::cout <<'|'<< std::endl;
		std::cout << "     |";
		for (unsigned j = 0; j < WIDTH; j++) {
			map[i][j]->printPart(part);
		}
		std::cout << '|' << std::endl;
	}

	printBorderDown();
}

Square* Map::IndexSquare(int i, int j)throw(std::out_of_range){
	if (i >= 8 || i < 0 || j >= 8 || j < 0 )
		throw std::out_of_range("indSqu");

	return map[i][j];
}

void Map::printBorderDown()const {
	std::cout << "     |";
	char letter = 'A';
	for (unsigned i = 0, j = 0; i < 50; i++, j++) {
		if (j == 6) {
			std::cout << '|';
			j = 0; letter += 1;
		}
		else if (j == 2) {
			std::cout << letter;
		}
		else std::cout << ' ';
	}std::cout << std::endl;
}

bool Map::in_bounds(int r)const {
	return r>= 0 && r<8;
}