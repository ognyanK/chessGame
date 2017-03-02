#include "Square.h"

Square::Square()
{
}
Square::Square(int i,int j)
{
	if (i % 2 == 0) {
		if (j % 2 == 0)
			squareColor = 1;
		else
			squareColor = 0;
	}
	else {
		if (j % 2 == 0)
			squareColor = 0;
		else
			squareColor = 1;
	}
	
	if (i <= 1 || i >= 6) {
		fig = Figure::VirtualConstructor(i,j);
	}
	else {
		fig = NULL;
	}
}

void Square::printPart(int a)const{
	if (a == 1) {
		if (squareColor)
			std::cout << "******";
		else
			std::cout << "      ";
	}
	else {
		if (squareColor) {
			std::cout << "**";
			if (fig == NULL) std::cout << "**";
			else std::cout << *fig;
			std::cout << "**";
		}
		else {
			std::cout << "  ";
			if (fig == NULL) std::cout << "  ";
			else std::cout << *fig;
			std::cout << "  ";
		}
	}
}

Figure* Square::getFigure()/*throws a nullptr exp*/ {
	return fig;
}

Figure* Square::getFigure_s(const std::string* t)throw(int){
	if (fig != NULL) {
		if (fig->getColor() == (*t)[0])
			return fig;
		else
			throw 30;//wrong figure code
	}
	else
		throw 20; //null ptr code
}
void Square::setFigure(Figure* f) {
	fig = f;
}
void Square::delFigure() {
	fig = NULL;
}