#include <exception>
#include "Map.h"
using namespace std;

void nextMove(Map&);
const string white = "WHITE", black = "BLACK";
const string* turn = &white;

int main() {
	Map board;

	do {
		system("cls");//clean consloe
		board.PrintMap();//print map
		cout << "it's " << *turn << "'s turn!" << endl;
		nextMove(board);

	} while (true);

	system("pause");
}

void nextMove(Map& board) {
	string startPos, endingPos;
	cout << "Enter a figure to move:" << endl;
	cin >> startPos;

	if (startPos.length() == 2) {
		int col = static_cast<int>(toupper(startPos[0])) - 65; //parse col to appropr number;
		int row = startPos[1]-49; //parse row to appropr number;

		try {
			board.IndexSquare(row, col)->getFigure_s(turn)->PossibleMoves(board, row, col);		//check if a person is selecting
																								//a square with figure. Check if it's
			cin >> endingPos;																	//his turn; If it's a valid figure;
			if (endingPos.length() == 2) {
				int col2 = static_cast<int>(toupper(endingPos[0])) - 65;
				int row2 = endingPos[1] - 49;
				board.IndexSquare(row, col)->getFigure()->Move(board, row2, col2,row,col);
			}
		}
		catch (int i) {
			if (i == 20)cout << "No figures of yours on this square" << endl;
			else if (i == 30)cout << "Not your figure, mate!" << endl;
			else if (i == 40)cout << "Nowhere to move this one :(" << endl;
			else if (i == 50)cout << "Invalid move, try again" << endl;
			system("pause");
			return;
		}
		catch (...) /*cathes out of bounds + nullFigure*/ {									
			return;
		}

		if (*turn == white)
			turn = &black;
		else
			turn = &white;
	}

	//system("pause");
}