#include <iostream>;
#include "Solution.h";
//cout << boolalpha to print true false easy
using namespace std;

int main() {
	Solution solution;
	int a1[] = { 2, 4, 9 };
	int a2[] = { 5, 6, 4, 9 };
	vector<int> array1 = solution.createVectorFromArray(a1, 3);
	vector<int> array2 = solution.createVectorFromArray(a2, 4);
	ListNode* listNode1 = solution.createLinkList(array1);
	ListNode* listNode2 = solution.createLinkList(array2);
	solution.printLinkList(listNode1);
	solution.printLinkList(listNode2);
	solution.printLinkList(solution.addTwoNumbers(listNode1, listNode2));
}