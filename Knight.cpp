#include "Knight.h"
#include "Map.h"

Knight::Knight()
{
}

Knight::Knight(char color):Figure(color, 'N') {

}

void Knight::PossibleMoves(Map& board, int row, int col,bool)throw(int) {
	moves.clear();
	int twos[2] = { -2,2 };
	int ones[2] = { -1,1 };
	char COLOR_DEPENDER;
		if (getColor() == 'W')
			COLOR_DEPENDER = 'B';
		else
			COLOR_DEPENDER = 'W';
	for (unsigned t = 0; t < 2; t++) {
		for (unsigned i = 0; i < 2; i++) {
			for (unsigned j = 0; j < 2; j++) {
				int useRow, useCol;
				if (t == 0) {
					useRow = row - twos[i];
					useCol = col - ones[j];
				}
				else {
					useRow = row - ones[i];
					useCol = col - twos[j];
				}
				if (board.in_bounds(useRow) && board.in_bounds(useCol) && 
					(board.IndexSquare(useRow, useCol)->getFigure() == NULL ||
					board.IndexSquare(useRow, useCol)->getFigure()->getColor()==COLOR_DEPENDER)) { //returns false if in bounds;
					moves.push_back(board.IndexSquare(useRow, useCol));
					std::cout << static_cast<char>(useCol + 65) << useRow + 1 << ' ';
				}
			}
		}
	}

	if (moves.size() == 0)throw 40; //no moves for this figure possible;
	std::cout << std::endl;
}


Knight::~Knight()
{
}
