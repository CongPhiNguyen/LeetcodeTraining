#include <iostream>;
#include "Solution.h";


using namespace std;
int main() {
	vector<string> input = { "flower","flow","flight" };
	Solution s;
	cout << s.longestCommonPrefix(input);
	return 0;
}