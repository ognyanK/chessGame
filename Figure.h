#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include <vector>
class Map;
class Square;

class Figure
{
public:
	Figure();
	Figure(char,char);
	static Figure* VirtualConstructor(int,int);
	void Move(Map&, int, int, int, int);
	virtual void PossibleMoves(Map& ,int,int,bool=false);
	virtual ~Figure();
	friend std::ostream& operator<<(std::ostream& str, const Figure& obj);
	char getColor()const { return color; }
	bool canCastle()const { return castle; }
protected:
	std::vector<Square*> moves;
private:
	char color;
	char figureName;
	bool castle; // only for king and rooks;
};

#endif // !FIGURE_H
