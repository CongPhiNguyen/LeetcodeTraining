#include <iostream>;
#include <string>;
// Import ở challenge 14
#include <vector>;
// Import ở challenge 20
#include <stack>;

#include <map>;

#include <set>

#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
	// Leetcode challenge 3: Medium
	// Find length of the longest substring without duplicate a single char
	int lengthOfLongestSubstring(string s);
	// Leetcode challenge 5: Medium
	string longestPalindrome(string s);
	// Leetcode challenge 8: Medium
	int myAtoi(string s);
	// Leetcode challenge 58:
	int lengthOfLastWord(string s);
	// Leetcode challenge 66
	vector<int> plusOne(vector<int>& digits);
	// Leetcode challenge 67
	string addBinary(string a, string b);
	// Leetcode challenge 69
	// Square root without using sqrt
	int mySqrt(int x);

	// Leetcode challge 36: Medium
	bool isValidSudoku(vector<vector<char>>& board);
	// Leetcode challenge 37: Hard
	void solveSudoku(vector<vector<char>>& board);
	vector<int> locationOfEmptyCell(vector<vector<char>> board);
	bool checkCombination(vector<vector<char>> board,
		vector<int> emptyCell,
		vector<char> filledEmptyCell, int index);
	// Leetcode challenge 83
	ListNode* deleteDuplicates(ListNode* head);
	// Leetcode challenge 88
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
	// Leetcode challenge 94
	vector<int> inorderTraversal(TreeNode* root);
	//Leetcode challenge 100
	bool isSameTree(TreeNode* p, TreeNode* q);
	//Leetcode challenge 101
	bool isSymmetric(TreeNode* root);
	//Leetcode challenge 104
	int maxDepth(TreeNode* root);
	// Leetcode challenge 118
	vector<vector<int>> pascalTriangle(int numRows);
	// Leetcode challenge 119
	vector<int> getRow(int rowIndex);
	// Leetcode challenge 121
	int maxProfit(vector<int>& prices);
	// Leetcode challenge 125
	bool isPalindromeUpgrade(string s);
	// Leetcode challenge 217
	bool containsDuplicate(vector<int>& nums);
	// Leetcode challenge 560: Medium
	int subarraySum(vector<int>& nums, int k);
	// Leetcode challenge 567: Medium
	bool checkInclusion(string s1, string s2);

	// MEDIUM
	// Leetcode chanllenge 56 Merge Intervals
	static bool comp(vector<int> a, vector<int> b) {
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		// sort array
		sort(intervals.begin(), intervals.end(), comp);


		vector<vector<int>> res;
		vector<int> currentInterval = intervals[0];
		int currentIndex = 1;
		while (currentIndex != intervals.size()) {
			if (currentInterval[1] >= intervals[currentIndex][0]) {
				if (intervals[currentIndex][1] > currentInterval[1])
					currentInterval[1] = intervals[currentIndex][1];
			}
			else {
				res.push_back(currentInterval);
				currentInterval = intervals[currentIndex];
			}
			currentIndex++;
		}
		res.push_back(currentInterval);
		return res;
	}


	// Leetcode challenge 1013
	bool canThreePartsEqualSum(vector<int>& arr) {
		int sum = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];
		}
		if (sum % 3 != 0) return false;
		int partition = sum / 3;

		// Xem thử có đoạn đầu = sum /3 hay không
		int index = 0;
		int currentSum = 0;
		for (int i = index; i < arr.size(); i++) {
			currentSum += arr[i];
			if (currentSum == partition) {
				index = i + 1;
				break;
			}
		}
		if (index == arr.size()) return false;
		// Xem thử đoạn sau có sum / 3 hay không
		currentSum = 0;
		for (int i = index; i < arr.size(); i++) {
			currentSum += arr[i];
			if (currentSum == partition) {
				index = i+1;
				if (index == arr.size()) return false;
				return true;
			}
		}
		
		return false;
	}

	// Leetcode 1991
	int findMiddleIndex(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int sumBegin = 0, sumEnd = 0;
		int currentMiddle = nums.size() - 1;
		int res = currentMiddle;
		bool isOk = false;
		for (int i = 0; i < nums.size() - 1; i++) {
			sumBegin += nums[i];
		}
		while (currentMiddle >= 0) {
			if (sumBegin == sumEnd) {
				res = currentMiddle;
				isOk = true;
			} 
			if (currentMiddle >= 1) {
				sumBegin -= nums[currentMiddle - 1];
				sumEnd += nums[currentMiddle];
			}
			currentMiddle--;
		}
		return isOk ? res : -1;
	}
	// Framework
	
	vector<int> createVectorFromArray(int a[], int length);
	void printLinkList(ListNode* head);
	ListNode* createLinkList(const vector<int>& a);
	void printVector(const vector<int>& a);
	bool isPrime(int n);


	// Sudoku
	vector<vector<char>> createSudokuBoard(char a[9][9]);
	vector<int> vectorFromIntArray(int a[], int n);
	vector<char> vectorFromCharArray(char a[], int n);
};

