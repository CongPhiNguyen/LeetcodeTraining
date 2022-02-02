#include <iostream>;
#include "Solution.h";
//cout << boolalpha to print true false easy
using namespace std;

int main() {
	Solution solution;
	char a[9][9] = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	vector<vector<char>> board = solution.createSudokuBoard(a);
	vector<int> emptyCell = solution.locationOfEmptyCell(board);
	vector<char> filledEmptyCell;
	filledEmptyCell.resize(emptyCell.size(), '.');
	filledEmptyCell[0] = '1';

	/*for (int i = 0; i < emptyCell.size(); i++) {
		cout << emptyCell{i} << ' ';
	}*/
	//cout << '\n';
	solution.solveSudoku(board);
}