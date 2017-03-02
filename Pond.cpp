#include "Pond.h"
#include "Map.h"

Pond::Pond()
{
}
Pond::Pond(char color):Figure(color,'P') {

}

void Pond::PossibleMoves(Map& board,int row,int col,bool)throw(int){
	moves.clear();
	if (getColor() == 'W') {
		if (row - 1 >= 0 && board.IndexSquare(row - 1, col)->getFigure() == NULL) { // move 1 step forward
			moves.push_back(board.IndexSquare(row - 1, col));
			std::cout << static_cast<char>(col + 65) << row <<' ';
		}
		if (row == 6 && board.IndexSquare(row - 2, col)->getFigure() == NULL
			&& board.IndexSquare(row - 1, col)->getFigure() == NULL) {	// move 2 steps forward
			moves.push_back(board.IndexSquare(row - 2, col));
			std::cout <<  static_cast<char>(col+65)<< row - 1 << ' ';
		}
		if (col - 1 >= 0 && row - 1 >= 0 && board.IndexSquare(row - 1, col - 1)->getFigure()!=NULL //take left
			&& board.IndexSquare(row - 1, col - 1)->getFigure()->getColor()=='B') {
				moves.push_back(board.IndexSquare(row - 1, col-1));
				std::cout << static_cast<char>(col-1 + 65) << row << ' ';
		}
		if (col + 1 <8 && row - 1 >= 0 && board.IndexSquare(row - 1, col + 1)->getFigure() != NULL  //take right
			&& board.IndexSquare(row - 1, col + 1)->getFigure()->getColor() == 'B') {
			moves.push_back(board.IndexSquare(row - 1, col + 1));
			std::cout << static_cast<char>(col + 1 + 65) << row << ' ';
		}
	}
	else {
		if (row + 1 < 8 && board.IndexSquare(row + 1, col)->getFigure() == NULL) {
			moves.push_back(board.IndexSquare(row + 1, col));
			std::cout << static_cast<char>(col + 65) << row + 2 << ' ';
		}
		if (row == 1 && board.IndexSquare(row + 2, col)->getFigure() == NULL
			&& board.IndexSquare(row + 1, col)->getFigure() == NULL) {
			moves.push_back(board.IndexSquare(row + 2, col));
			std::cout << static_cast<char>(col + 65) << row + 3 << ' ';
		}
		if (col - 1 >= 0 && row + 1 <8 && board.IndexSquare(row + 1, col - 1)->getFigure() != NULL //take left
			&& board.IndexSquare(row + 1, col - 1)->getFigure()->getColor() == 'W') {
			moves.push_back(board.IndexSquare(row + 1, col - 1));
			std::cout << static_cast<char>(col - 1 + 65) << row+2 << ' ';
		}
		if (col + 1 <8 && row + 1 <8 && board.IndexSquare(row + 1, col + 1)->getFigure() != NULL //take right
			&& board.IndexSquare(row + 1, col + 1)->getFigure()->getColor() == 'W') {
			moves.push_back(board.IndexSquare(row + 1, col + 1));
			std::cout << static_cast<char>(col + 1 + 65) << row + 2 << ' ';
		}
	}
	if (moves.size() == 0)throw 40; //no moves for this figure possible;

	std::cout <<std::endl;
}

Pond::~Pond()
{
}
