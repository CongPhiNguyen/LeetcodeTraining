#include <iostream>;
#include "Solution.h";
//cout << boolalpha to print true false easy
using namespace std;

int main() {
	Solution solution;
	int a[] = { 1,2,3,0,0,0 };
	vector<int> m1 = solution.vectorFromIntArray(a, 6);
	int b[] = { -10,-7,0 };
	vector<int> m2 = solution.vectorFromIntArray(b, 3);
	solution.merge(m1, 3, m2, 3);
	solution.printVector(m1);



	//cout << boolalpha << solution;
}