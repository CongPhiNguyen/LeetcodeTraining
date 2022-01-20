#include <iostream>;
#include "Solution.h";

//cout << boolalpha to print true false easy
using namespace std;
int main() {
	ListNode* a2 = new ListNode(4);
	ListNode* a1 = new ListNode(3, a2);
	ListNode* a = new ListNode(1, a1);

	ListNode* b2 = new ListNode(4);
	ListNode* b1 = new ListNode(2, b2);
	ListNode* b = new ListNode(1, b1);

	Solution solution;
	ListNode* res = solution.mergeTwoLists(a, b);
	while (res != nullptr)
	{
		cout << res -> val << " ";
		res = res->next;
	}
	return 0;

	delete b;
	delete b1;
	delete b2;
	delete a;
	delete a1;
	delete a2;
	delete res;
}