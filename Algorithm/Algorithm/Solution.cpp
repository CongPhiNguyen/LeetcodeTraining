#include "Solution.h"
// Leetcode challenge 13
int Solution::romanToInt(string s)
{
	int result = 0;
	string pattern[6] = { "IV", "IX", "XL", "XC", "CD", "CM" };
	int value[6] = { 4, 9, 40, 90, 400, 900 };
	for (int i = 0; i < 6; i++)
	{
		int findValue = s.find(pattern[i]);
		if (findValue != -1)
		{
			result += value[i];
			s = s.replace(findValue, 2, "");
		}
	}
	string basicPatterns[7] = { "I", "V", "X", "L", "C", "D", "M" };
	int basicValue[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	for (int i = 0; i < 7; i++)
	{
		int findValue = s.find(basicPatterns[i]);
		while (findValue != -1)
		{
			result += basicValue[i];
			s = s.replace(findValue, 1, "");
			findValue = s.find(basicPatterns[i]);
		}
	}
	return result;
}
// Leetcode challenge 14
string compareString(string str1, string str2) {
	int length = str1.size();
	if (str2.size() < str1.size())
	{
		length = str2.size();
	}
	string result = "";
	for (int i = 0; i < length; i++)
	{
		if (str1[i] == str2[i])
		{
			result += str1[i];
		}
		else break;
	}
	return result;
}
string Solution::longestCommonPrefix(vector<string>& strs) {
	string result = strs[0];
	for (int i = 1; i < strs.size(); i++)
	{
		result = compareString(result, strs[i]);
	}
	return result;
}
// Leetcode challenge 20
bool Solution::isValid(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')')
		{
			if (st.size() == 0) return false;
			if (st.top() == '(')
				st.pop();
			else return false;
		}
		else if (s[i] == '}')
		{
			if (st.size() == 0) return false;
			if (st.top() == '{')
				st.pop();
			else return false;
		}
		else if (s[i] == ']') {
			if (st.size() == 0) return false;
			if (st.top() == '[') 
				st.pop();
			else return false;
		}
	}
	if (st.size() == 0)
		return true;
	else return false;
}
// Leetcode challenge 21
ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode* result = nullptr;
	ListNode* resultCal = nullptr;
	ListNode* resultImplement = nullptr;
	ListNode* nodeList1 = list1;
	ListNode* nodeList2 = list2;
	bool isAssign = false;
	//int step = 0;
	while (nodeList1 != nullptr || nodeList2 != nullptr)
	{
		if (nodeList1 != nullptr) {
			if (nodeList2 != nullptr)
			{
				if (nodeList1 -> val <= nodeList2 -> val) {
					if (!isAssign) {
						result = nodeList1;
						resultCal = result;
						//cout << "Assign " << result->val << "\n";
					}
					resultImplement = nodeList1;
					
					//cout << step++ << " " << resultImplement->val << "\n";

					nodeList1 = nodeList1->next;
					if (isAssign) {
						resultCal->next = resultImplement;
						resultCal = resultCal->next;
					}
					resultImplement = resultImplement->next;
					isAssign = true;
				}
				else {
					if (!isAssign) {
						result = nodeList2;
						resultCal = result;
						//cout <<"Assign " << result -> val << "\n";
					}
					resultImplement = nodeList2;

					//cout << step++ << " " << resultImplement->val << "\n";

					nodeList2 = nodeList2->next;
					if (isAssign) {
						resultCal->next = resultImplement;
						resultCal = resultCal->next;
					}
					resultImplement = resultImplement->next;
					isAssign = true;
				}
			}
			else {
				if (!isAssign) {
					result = nodeList1;
					resultCal = result;
					//cout << "Assign " << result->val << "\n";
				}
				resultImplement = nodeList1;

				//cout << step++ << " " << resultImplement->val << "\n";

				nodeList1 = nodeList1 -> next;
				if (isAssign) {
					resultCal->next = resultImplement;
					resultCal = resultCal->next;
				}
				resultImplement = resultImplement->next;
				isAssign = true;
			}
		}
		else {
			if (!isAssign) {
				result = nodeList2;
				resultCal = result;
				//cout << "Assign " << result->val << "\n";
			}
			resultImplement = nodeList2;

			//cout << step++ << " " << resultImplement->val <<"\n";

			nodeList2 = nodeList2 -> next;
			if (isAssign) {
				resultCal ->next = resultImplement;
				resultCal = resultCal->next;
			}
			resultImplement = resultImplement -> next;
			isAssign = true;
		}
	}
	return result;
}
// Leetcode challenge 26
int Solution::removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	vector<int> a;
	a.push_back(nums[0]);
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > nums[i - 1]) {
			a.push_back(nums[i]);
		}
	}
	nums = vector<int>(a);
	return a.size();
}
// Leetcode challenge 27
int Solution::removeElement(vector<int>& nums, int val) {
	vector<int> a;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != val) {
			a.push_back(nums[i]);
		}
	}
	nums = vector<int>(a);
	return a.size();
}
// Leetcode challenge 28
int Solution::strStr(string haystack, string needle) {
	if (needle.size() == 0) return 0;
	return haystack.find(needle);
}
// Leetcode challenge 35
int Solution::searchInsert(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= target) return i;
	}
	return nums.size();
}
// Leetcode challenge 53
int Solution::maxSubArray(vector<int>& nums) {
	int result = 0;
	int maxSum = 0;
	int maxNegative = -999999;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0)
		{
			if (maxSum < result)
				maxSum = result;
			if (maxNegative < nums[i])
			{
				maxNegative = nums[i];
			}
		}
		else {
			maxNegative = 100;
		}
		if ((result + nums[i]) <= 0)
		{
			if (maxSum < result)
				maxSum = result;
			result = 0;
		}
		else {
			result += nums[i];
		}
	}
	if (maxNegative < 0) return maxNegative;
	if (maxSum > result) return maxSum;
	else return result;
}
// Leetcode challenge 2
vector<int> Solution::createVectorFromArray(int a[], int length)
{
	vector<int> result;
	for (int i = 0; i < length; i++)
	{
		result.push_back(a[i]);
	}
	return result;
}
void Solution::printLinkList(ListNode* head)
{
	cout << "Linked list: ";
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << "\n";
}
void printVector(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return;
}
void printLinkListVector(vector<ListNode*> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] -> val << " ";
	}
	cout << "\n";
	return;
}
ListNode* Solution::createLinkList(const vector<int>& a) {
	vector<ListNode*> list;
	for (int i = 0; i < a.size(); i++) {
		ListNode* node = new ListNode(a[i]);
		list.push_back(node);
	}
	for (int i = 0; i < list.size() - 1; i++) {
		list[i]->next = list[i + 1];
	}
	return list[0];
}
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	// Add them to vector
	vector<ListNode*> listL1, listL2;
	while (l1 != nullptr) {
		listL1.push_back(l1);
		l1 = l1->next;
	}
	while (l2 != nullptr) {
		listL2.push_back(l2);
		l2 = l2->next;
	}

	printLinkListVector(listL1);
	printLinkListVector(listL2);

	int expectedLength = listL1.size();
	if (listL1.size() < listL2.size())
	{
		expectedLength = listL2.size();
	}

	int memNum = 0;
	vector<ListNode*> result;
	for (int i = 0; i < expectedLength; i++) {
		int sum = memNum;
		if (listL1.size() > i) {
			sum += listL1[i]->val;
		}
		if (listL2.size() > i) {
			sum += listL2[i]->val;
		}
		if (sum >= 10) {
			sum -= 10;
			memNum = 1;
		}
		else
			memNum = 0;
		result.push_back(new ListNode(sum));
	}
	if (memNum != 0) {
		result.push_back(new ListNode(1));
	}
	for (int i = 0; i < result.size() - 1; i++) {
		result[i]->next = result[i + 1];
	}
	return result[0];
}