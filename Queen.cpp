#include "Queen.h"
#include "Map.h"
#include <algorithm>

Queen::Queen()
{
}
Queen::Queen(char color) :Rook(color, 'Q'){
	in_terms_of = new Bishop(color);
}

void Queen::PossibleMoves(Map& board, int row, int col,bool)throw(int) {
	moves.clear();
	Rook::PossibleMoves(board,row,col,1);// this 1 is to disable expeption bishking and endlining;
	in_terms_of->PossibleMoves(board, row, col,1);// this 1 is to disable expeption bishking and endlining;
	moves.insert(std::end(moves), std::begin(in_terms_of->moves), std::end(in_terms_of->moves));

	if (moves.size() == 0)throw 40; //no moves for this figure possible;
	std::cout << std::endl;
}

Queen::~Queen()
{
}
