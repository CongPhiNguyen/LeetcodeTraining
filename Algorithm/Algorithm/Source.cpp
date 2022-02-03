#include <iostream>;
#include "Solution.h";
//cout << boolalpha to print true false easy
using namespace std;

int main() {
	Solution solution;
	char a[9][9] = {
		{'.','.','9','7','4','8','.','.','.'},
		{'7','.','.','.','.','.','.','.','.'},
		{'.','2','.','1','.','9','.','.','.'},
		{'.','.','7','.','.','.','2','4','.'},
		{'.','6','4','.','1','.','5','9','.'},
		{'.','9','8','.','.','.','3','.','.'},
		{'.','.','.','8','.','3','.','2','.'},
		{'.','.','.','.','.','.','.','.','6'},
		{'.','.','.','2','7','5','9','.','.'}
	};
	vector<vector<char>> board = solution.createSudokuBoard(a);

	/*for (int i = 0; i < emptyCell.size(); i++) {
		cout << emptyCell{i} << ' ';
	}*/
	//cout << '\n';
	solution.solveSudoku(board);
}