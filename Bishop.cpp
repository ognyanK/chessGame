#include "Bishop.h"
#include "Map.h"


Bishop::Bishop()
{
}
Bishop::Bishop(char color) :Figure(color, 'B') {

}
void Bishop::PossibleMoves(Map& board, int row, int col,bool check)throw(int) {
	moves.clear();

	int ones[2] = { 1,-1 };

	char COLOR_DEPENDER;
	if (getColor() == 'W')
		COLOR_DEPENDER = 'B';
	else
		COLOR_DEPENDER = 'W';
	
	for (unsigned t = 0; t < 2; t++) {
		for (unsigned k = 0; k < 2; k++) {
			for (unsigned i = row - ones[t], j = col - ones[k]; board.in_bounds(i); i-=ones[t], j-=ones[k]) {
				if (board.in_bounds(j)) {
					if (board.IndexSquare(i, j)->getFigure() == NULL) {
						moves.push_back(board.IndexSquare(i, j));
						std::cout << static_cast<char>(j + 65) << i + 1 << ' ';
					}
					else if (board.IndexSquare(i, j)->getFigure()->getColor() == COLOR_DEPENDER) {
						moves.push_back(board.IndexSquare(i, j));
						std::cout << static_cast<char>(j + 65) << i + 1 << ' ';
						break;
					}
					else {
						break;
					}
				}
			}
		}
	}

	if (moves.size() == 0 && !check)throw 40; //no moves for this figure possible;
	if(!check)std::cout << std::endl;
}
Bishop::~Bishop()
{
}
