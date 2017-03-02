#include "King.h"
#include "Map.h"


King::King()
{
}

King::King(char color) : Figure(color, 'K'){

}

void King::PossibleMoves(Map& board, int row, int col,bool)throw(int) {
	moves.clear();
	char COLOR_DEPENDER;
	if (getColor() == 'W')
		COLOR_DEPENDER = 'B';
	else
		COLOR_DEPENDER = 'W';

	int arr[3] = { -1,0,1 };
	
	for (unsigned i = 0; i < 3; i++) {
		for (unsigned j = 0; j < 3; j++) {
			if (arr[i] == 0 && arr[j] == 0)j++;

			int useRow = row + arr[i];
			int useCol = col + arr[j];

			if (board.in_bounds(useRow)&&board.in_bounds(useCol)&&
				(
				board.IndexSquare(useRow, useCol)->getFigure() == NULL ||
				board.IndexSquare(useRow,useCol)->getFigure()->getColor() == COLOR_DEPENDER
				)
			   )
			{
				moves.push_back(board.IndexSquare(useRow, useCol));
				std::cout << static_cast<char>(useCol+65) << useRow+1 << ' ';
			}
		}
	}

	ExamineCastlePossibilities(board, row, col);

	if (moves.size() == 0)throw 40; //no moves for this figure possible;
	std::cout << std::endl;
}

void King::ExamineCastlePossibilities(Map& board, int row, int col) {
	if (board.IndexSquare(row, col)->getFigure()->canCastle()) {
		int i = col + 1;
		bool free = true;
		for (; i < 7; i++) {
			if (board.IndexSquare(row, i)->getFigure() != NULL) {
				free = false;
			}
		}
		if (free&&board.IndexSquare(row, i)->getFigure()->canCastle()) {
			moves.push_back(board.IndexSquare(row, i - 1));
			std::cout << static_cast<char>(i - 1 + 65) << row + 1 << ' ';
		}
		i = col - 1;
		free = true;
		for (; i >0; i--) {
			if (board.IndexSquare(row, i)->getFigure() != NULL) {
				free = false;
			}
		}
		if (free&&board.IndexSquare(row, i)->getFigure()->canCastle()) {
			moves.push_back(board.IndexSquare(row, i + 2));
			std::cout << static_cast<char>(i + 2 + 65) << row + 1 << ' ';
		}
	}
}

King::~King()
{
}
