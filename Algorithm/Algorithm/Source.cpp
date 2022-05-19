#include <iostream>;
#include "Solution.h";
//cout << boolalpha to print true false easy
using namespace std;

int main() {
	Solution solution;
	/*int a[] = { 1,2,3,0,0,0 };
	vector<int> m1 = solution.vectorFromIntArray(a, 6);
	int b[] = { -10,-7,0 };
	vector<int> m2 = solution.vectorFromIntArray(b, 3);
	solution.merge(m1, 3, m2, 3);*/
	//solution.printVector(solution.getRow(5));

	/*int a[] = { 0,0,0,0 };
	vector<int> m1 = solution.vectorFromIntArray(a, 4);
	cout << solution.findMiddleIndex(m1);*/

	//cout << boolalpha << solution;

	cout << boolalpha << solution.isPrime(1);
	cout << boolalpha << solution.isPrime(2);
	cout << boolalpha << solution.isPrime(3);
	cout << boolalpha << solution.isPrime(4);
	cout << boolalpha << solution.isPrime(5);

}