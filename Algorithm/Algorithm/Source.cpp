#include <iostream>;
#include "Solution.h";
//cout << boolalpha to print true false easy
using namespace std;

int main() {
	Solution solution;
	int a[] = { 1,2,1,2,1 };
	vector<int> input;
	for (int i = 0; i < 5; i++)
	{
		input.push_back(a[i]);
	}
	cout << boolalpha << solution.subarraySum(input, 3);
}