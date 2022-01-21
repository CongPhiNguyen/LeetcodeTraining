#include <iostream>;
#include <string>;
// Import ở challenge 14
#include <vector>;
// Import ở challenge 20
#include <stack>;

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#pragma once
class Solution
{
public:
	// Leetcode challenge 13
	int romanToInt(string s);
	// Leetcode challenge 14
	string longestCommonPrefix(vector<string>& strs);
	// Leetcode challenge 20
	bool isValid(string s);
	// Leetcode challenge 21
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
	// Leetcode challenge 26
	int removeDuplicates(vector<int>& nums);
	// Leetcode challenge 27
	int removeElement(vector<int>& nums, int val);
	// Leetcode challenge 28
	int strStr(string haystack, string needle);
	// Leetcode challenge 35
	int searchInsert(vector<int>& nums, int target);
	// Leetcode challenge 53
	int maxSubArray(vector<int>& nums);
	// Leetcode challenge 2
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);


	// Framework
	vector<int> createVectorFromArray(int a[], int length);
	void printLinkList(ListNode* head);
	ListNode* createLinkList(const vector<int>& a);
};

