﻿#include <iostream>;
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
};

