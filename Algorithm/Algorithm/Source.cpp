#include <iostream>;
#include "Solution.h";

//cout << boolalpha to print true false easy
using namespace std;
int main() {
	string s = ")";
	Solution solution;
	cout << boolalpha << solution.isValid(s);
	return 0;
}