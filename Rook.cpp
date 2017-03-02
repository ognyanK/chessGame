#include "Rook.h"
#include "Map.h"


Rook::Rook()
{
}
Rook::Rook(char color) :Figure(color, 'R') {}
Rook::Rook(char color,char name) : Figure(color, name) {}

void Rook::PossibleMoves(Map& board, int row, int col,bool check)throw(int) {
	moves.clear();

	int helper[4] = { 0,0,1,-1 };

	char COLOR_DEPENDER;
	if (getColor() == 'W')
		COLOR_DEPENDER = 'B';
	else
		COLOR_DEPENDER = 'W';


		for (int i=0, j = 3; j >= 0; i++,j--) {
			for (unsigned r = row + helper[i], c = col + helper[j]; board.in_bounds(c)&&board.in_bounds(r); c += helper[j],r+=helper[i]) {
				if (board.IndexSquare(r, c)->getFigure() == NULL) {
					moves.push_back(board.IndexSquare(r, c));
					std::cout << static_cast<char>(c + 65) << r + 1 << ' ';
				}
				else if (board.IndexSquare(r, c)->getFigure()->getColor() == COLOR_DEPENDER) {
					moves.push_back(board.IndexSquare(r, c));
					std::cout << static_cast<char>(c + 65) << r + 1 << ' ';
					break;
				}
				else {
					break;
				}
			}
		}

	

	if (moves.size() == 0 && !check)throw 40; //no moves for this figure possible;
	if (!check)std::cout << std::endl;
}

Rook::~Rook()
{
}
