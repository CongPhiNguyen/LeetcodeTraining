#include <iostream>;
#include "Solution.h";

//cout << boolalpha to print true false easy
using namespace std;
int main() {
	Solution solution;
	vector<int> b;
	b.push_back(0);
	b.push_back(0);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(2);
	b.push_back(2);
	b.push_back(3);
	b.push_back(3);
	b.push_back(4);
	cout << "length: " << solution.removeDuplicates(b);
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}