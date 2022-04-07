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
// Leetcode challenge 3
int Solution::lengthOfLongestSubstring(string s) {
	//// Các thao tác căn bản với map
	//map<int, int> mp;

	//mp[0] = 1;
	//mp[1] = 4;
	//
	//map<int, int>::iterator it;
	//for (it = mp.begin(); it != mp.end(); it++) {
	//	cout << it->first << " -> " << it->second << "\n";
	//}
	//cout << mp.count(5) << "\n";

	cout << "String: " << s << "\n";
	// Thực hiện các bước của thuật toán
	int start = 0, end = 0;
	int result = 0;
	// Đếm và thêm ký tự vào map
	map<char, int> mpHash;
	for (end = 0; end < s.size(); end++)
	{
		// Trường hợp ko tìm thấy và thêm index vào
		if (mpHash.count(s[end]) == 0 || mpHash[s[end]] < start) {
			mpHash[s[end]] = end;
			if (end == s.size() - 1) {
				cout << "Special case\n";
				return max(result, end + 1 - start);
			}
		}
		// Trường hợp tìm thấy thì move start lên 1 rồi thực hiện tiếp các bước
		else {
			result = max(result, end - start);
			cout << "Result change: " << result << "\n";
			cout << "Start: " << start << "\n";
			cout << "End: " << end << "\n";

			start = mpHash[s[end]] + 1;
			mpHash[s[end]] = end;	
		}
	}
	return result;
}
// Leetcode challenge 5
bool isPalindrome(string s)
{
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 -i])
		{
			return false;
		}
	}
	return true;
}
string Solution::longestPalindrome(string s) {
	if (s.size() == 1) return s;
	// save location of each character
	vector<vector<int>> saveLocation;
	saveLocation.resize(126, vector<int>(0));
	for (int i = 0; i < s.size(); i++)
	{
		saveLocation[s[i]].push_back(i);
	}
	// Dò hết các vector có độ dài lớn hơn 2 để mà có thể giảm được lần check palindrome
	string result = {s[0]};
	for (int i = 0; i < saveLocation.size(); i++)
	{
		for (int j = 0; j + 1 < saveLocation[i].size(); j++)
		{
			cout << "J = " << j << "\n";
			for (int k = j + 1; k < saveLocation[i].size(); k++) {
				cout << "Check: " << saveLocation[i][j] <<" " << saveLocation[i][k] << " " << s.substr(saveLocation[i][j], saveLocation[i][k] - saveLocation[i][j] + 1) << "\n";
				if (saveLocation[i][k] - saveLocation[i][j] < result.length()) {
					continue;
				}
				else {
					if (isPalindrome(s.substr(saveLocation[i][j], saveLocation[i][k] - saveLocation[i][j] + 1)))
					{
						result = s.substr(saveLocation[i][j], saveLocation[i][k] - saveLocation[i][j] + 1);
						cout << "Result change: " << s.substr(saveLocation[i][j], saveLocation[i][k] - saveLocation[i][j] + 1) << "\n";
					}
				}
			}
		}
	}
	//// In cái vector ra để debug
	/*for (int i = 0; i < saveLocation.size(); i++)
	{
		cout << (char)(i + 'a') << " length: " << saveLocation[i].size() << " ";
		for (int j = 0; j < saveLocation[i].size(); j++)
		{
			cout << saveLocation[i][j] << " ";
		}
		cout << "\n";
	}*/

	return result;
}
// Leetcode challenge 8
int Solution::myAtoi(string s) {
	// Loại bỏ hết các khoảng trắng
	return 0;
}
// Leetcode challenge 58
int Solution::lengthOfLastWord(string s) {
	string resultString = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == ' ')
		{
			if (resultString != "") return resultString.length();
		}
		else {
			resultString += s[i];
		}
	}
	return resultString.length();
}
// Leetcode challenge 66
vector<int> Solution::plusOne(vector<int>&digits) {
	if (digits[digits.size() - 1] < 9) {
		digits[digits.size() - 1] = digits[digits.size() - 1] + 1;
		return digits;
	}
	else {
		vector<int> result;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] != 9) {
				digits[i] = digits[i] + 1;
				return digits;
			}
			else {
				digits[i] = 0;
				result.push_back(0);
				if (i == 0) {
					result.push_back(1);
					reverse(result.begin(), result.end());
					return result;
				}
			}
		}
	}
	return digits;
}
// Leetcode challenge 67
string Solution::addBinary(string a, string b) {
	string result = "";
	int lenga = a.size() - 1, lengb = b.size() - 1;
	int remember = 0;
	while (lenga != -1 && lengb != -1) {
		if (a[lenga] == '1' && b[lengb] == '1') {
			if (remember == 1)
			{
				result = '1' + result;
			}
			else {
				result = "0" + result;
			}
			remember = 1;
		}
		else if(a[lenga] == '0' && b[lengb] == '0'){
			if (remember == 1)
			{
				result = '1' + result;
			}
			else {
				result = "0" + result;
			}
			remember = 0;
		}
		else {
			if (remember == 1)
			{
				result = '0' + result;
				remember = 1;
			}
			else {
				result = "1" + result;
				remember = 0;
			}
		}
		lenga--;
		lengb--;
	}

	if (lenga > lengb) {
		while (lenga >= 0)
		{
			cout << "Stuck in round 1\n";
			if (remember == 1)
			{
				if (a[lenga] == '1') {
					result = "0" + result;
					remember = 1;
				}
				else {
					result = "1" + result;
					remember = 0;
				}
			}
			else {
				if (a[lenga] == '1') {
					result = "1" + result;
				}
				else {
					result = "0" + result;
				}
				remember = 0;
			}
			lenga--;
		}
		
	}
	else {
		while (lengb >= 0)
		{
			if (remember == 1)
			{
				if (b[lengb] == '1') {
					result = "0" + result;
					remember = 1;
				}
				else {
					result = "1" + result;
					remember = 0;
				}
			}
			else {
				if (b[lengb] == '1') {
					result = "1" + result;
				}
				else {
					result = "0" + result;
				}
				remember = 0;
			}
			lengb--;
		}
		
	}
	if (remember == 1)
	{
		result = "1" + result;
	}
	return result;
}
// Leetcode challnge 69
// Square root without using sqrt
int Solution::mySqrt(int x) {
	if (x == 0) return 0;
	double result = 1.0f;
	while (fabs(result * result - x) >= 0.1)
		result = (x / result - result) / 2 + result;
	return (int)result;
}

// Leetcode challenge 36
vector<vector<char>> Solution::createSudokuBoard(char a[9][9]) {
	vector<vector<char>> result;
	for (int i = 0; i < 9; i++) {
		vector<char> temp;
		for (int j = 0; j < 9; j++) {
			temp.push_back(a[i][j]);
		}
		result.push_back(temp);
	}
	return result;
}
bool Solution::isValidSudoku(vector<vector<char>>& board) {
	// Check hàng ngang
	for (int i = 0; i < 9; i++) {
		set<char> s;
		for (int j = 0; j < 9; j++) {
			if (s.count(board[i][j]) == 1)
			{
				return false;
			}
			else if (board[i][j] != '.') {
				s.insert(board[i][j]);
			}
		}
	}
	// Check hàng dọc
	for (int j = 0; j < 9; j++) {
		set<char> s;
		for (int i = 0; i < 9; i++) {
			if (s.count(board[i][j]) == 1)
			{
				return false;
			}
			else if (board[i][j] != '.') { 
				s.insert(board[i][j]); 
			}
		
		}
	}
	// Check các ô 3x3
	for (int i1 = 0; i1 < 3; i1++)
	{
		for (int j1 = 0; j1 < 3; j1++) {
			set<char> s;
			for(int i = 0 ; i < 3 ; i++)
			{
				for(int j = 0 ; j < 3; j++)
				{
					if (s.count(board[3 * i1 + i][3 * j1 + j]) == 1) {
						return false;
					}
					else if(board[3 * i1 + i][3 * j1 + j] != '.'){
						s.insert(board[3 * i1 + i][3 * j1 + j]);
					}
				}
			}
		}
	}

	return true;
}

// Leetcode challene 37
vector<int> Solution::locationOfEmptyCell(vector<vector<char>> board) {
	vector<int> result;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') {
				result.push_back(i * 9 + j);
			}
		}
	}
	return result;
}

vector<vector<char>> currentCopyBoard;
int currentIndex;
bool Solution::checkCombination(vector<vector<char>> board,
	vector<int> emptyCell, 
	vector<char> filledEmptyCell, int index) {
	
	if (currentCopyBoard.size() == 0) {
		currentCopyBoard = vector<vector<char>>(board);
	}
	else {
		if (currentIndex < index)
		{
			for (int i = currentIndex; i <= index; i++) {
				int x, y;
				x = emptyCell[i] / 9;
				y = emptyCell[i] % 9;

				currentCopyBoard[x][y] = filledEmptyCell[i];
			}
		}
		else {
			for (int i = index; i <= currentIndex; i++)
			{
				int x, y;
				x = emptyCell[i] / 9;
				y = emptyCell[i] % 9;

				currentCopyBoard[x][y] = '.';
			}
			int x, y;
			x = emptyCell[index] / 9;
			y = emptyCell[index] % 9;

			currentCopyBoard[x][y] = filledEmptyCell[index];
		}
		currentIndex = index;
	}

	int x = emptyCell[index] / 9;
	int y = emptyCell[index] % 9;
	// Check hàng dọc
	set<char> s;
	for (int i = 0; i < 9; i++)
	{
		if (currentCopyBoard[i][y] != '.')
		{
			if (s.count(currentCopyBoard[i][y]) == 1) {
				return false;
			}
			else {
				s.insert(currentCopyBoard[i][y]);
			}
		}
	}
	s.clear();
	// Check hàng ngang
	for (int i = 0; i < 9; i++)
	{
		if (currentCopyBoard[x][i] != '.')
		{
			if (s.count(currentCopyBoard[x][i]) == 1) {
				return false;
			}
			else {
				s.insert(currentCopyBoard[x][i]);
			}
		}
	}
	s.clear();
	// Check 3x3
	int i1 = x / 3;
	int j1 = y / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (s.count(currentCopyBoard[3 * i1 + i][3 * j1 + j]) == 1) {
				return false;
			}
			else if (currentCopyBoard[3 * i1 + i][3 * j1 + j] != '.') {
				s.insert(currentCopyBoard[3 * i1 + i][3 * j1 + j]);
			}
		}
	}
	return true;
}
vector<int> Solution::vectorFromIntArray(int a[], int n) {
	vector<int> result;
	for (int i = 0; i < n; i++) {
		result.push_back(a[i]);
	}
	return result;
}
vector<char> Solution::vectorFromCharArray(char a[], int n) {
	vector<char> result;
	for (int i = 0; i < n; i++) {
		result.push_back(a[i]);
	}
	return result;
}

void Solution::solveSudoku(vector<vector<char>>& board) {
	Solution solution;
	vector<int> emptyCell = solution.locationOfEmptyCell(board);
	vector<char> filledEmptyCell;
	filledEmptyCell.resize(emptyCell.size(), '.');

	int index = 0;
	while (index < emptyCell.size()) {
		if (filledEmptyCell[index] == '.') {
			filledEmptyCell[index] = '1';
			if (checkCombination(board, emptyCell, filledEmptyCell, index))
			{
				index++;
				/*for (int i = 0; i < filledEmptyCell.size(); i++)
				{
					cout << filledEmptyCell[i] << " ";
				}
				cout << "\n";*/
			}
		}
		else if (filledEmptyCell[index] == '9')
		{
			filledEmptyCell[index] = '.';
			index--;
			if (index == -1) {
				cout << "No solution\n";
				return;
			}
		}
		else {
			filledEmptyCell[index] = filledEmptyCell[index] + 1;
			if (checkCombination(board, emptyCell, filledEmptyCell, index))
			{
				index++;
				/*for (int i = 0; i < filledEmptyCell.size(); i++)
				{
					cout << filledEmptyCell[i] << " ";
				}
				cout << "\n";*/
			}
		}

		
	}
	//cout << "Finish\n";
	/*for (int i = 0; i < filledEmptyCell.size(); i++)
	{
		cout << filledEmptyCell[i] << " ";
	}
	cout << "\n";*/
	
	// Thay thế cái mảng chuỗi ban đầu
	for (int i = 0; i < emptyCell.size(); i++) {
		int x = emptyCell[i] / 9;
		int y = emptyCell[i] % 9;

		board[x][y] = filledEmptyCell[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

// Leetcode challenge 83
ListNode* Solution::deleteDuplicates(ListNode* head) {
	if (head == nullptr) return head;
	ListNode* a = head;
	while (a->next != nullptr) {
		if (a->val == a->next->val) {
			a->next = a->next->next;
		}
		else {
			a = a->next;
		}
	}
	return head;
}
// Leetcode challenge 88
void movePosition(vector<int>& a1, int position, int value) {
	if (a1.size() - 1 == position) {
		a1[position] = value;
		return;
	}
	for (int i = a1.size() - 1; i > position; i--)
	{
		a1[i] = a1[i - 1];
	}
	a1[position] = value;
	return;
}
void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	// Trường hợp all nums2 nhỏ hơn nums1 
	// Trường hợp all nums1 nhỏ hơn nums2 
	int currentIndex = 0;
	for (int i = 0; i < nums2.size(); i++) {
		while (nums1[currentIndex] <= nums2[i] && currentIndex < m) {
			currentIndex++;
		}
		movePosition(nums1, currentIndex, nums2[i]);
		currentIndex++;
		m++;
	}
}



// Leetcode challenge 94
void travel(TreeNode* root, vector<int>& result) {
	if (root == nullptr) return;
	travel(root->left, result);
	result.push_back(root->val);
	travel(root->right, result);
}

// Leetcode challenge 100
bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) {
		return true;
	}
	if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
		return false;
	}
	return (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right)) && (p->val == q->val);
}
// Leetcode challenge 101
bool isSyncTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) {
		return true;
	}
	if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
		return false;
	}
	return (isSyncTree(p->left, q->right)) && (isSyncTree(p->right, q->left))
		&& (p->val == q->val);
}
bool Solution::isSymmetric(TreeNode* root) {
	if (root == nullptr) return true;
	return isSyncTree(root->left, root->right);
}

// Leetcode challenge 104
int Solution::maxDepth(TreeNode* root) {
	if (root == nullptr) return 0;
	return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}

vector<int> Solution::inorderTraversal(TreeNode* root) {
	vector<int> result;
	travel(root, result);
	return result;
}
// Leetcode challenge 118
vector<vector<int>> Solution::pascalTriangle(int numRows) {
	vector<vector<int>> result;
	for (int i = 0; i < numRows; i++) {
		vector<int> rowIndex;
		if (i == 0)
		{
			rowIndex.push_back(1);
		}
		else if (i == 1)
		{
			rowIndex.push_back(1);
			rowIndex.push_back(1);
		}
		else {
			rowIndex.push_back(1);
			for (int i = 0; i < result[result.size() - 1].size() - 1; i++) {
				rowIndex.push_back(
					result[result.size() - 1][i] +
					result[result.size() - 1][i + 1]
				);
			}
			rowIndex.push_back(1);
		}
		result.push_back(rowIndex);
	}
	return result;
}
// Leetcode challenge 119
vector<int> Solution::getRow(int rowIndex) {
	vector<int> initialVector;
	initialVector.push_back(1);
	if (rowIndex == 0) return initialVector;
	while (rowIndex > 0) {
		vector<int> res;
		res.push_back(1);
		for (int i = 0; i < initialVector.size() - 1; i++) {
			res.push_back(initialVector[i] + initialVector[i + 1]);
		}
		res.push_back(1);
		initialVector = res;
		rowIndex--;
	}
	return initialVector;
}
// Leetcode challenge 121
int Solution::maxProfit(vector<int>& prices) {
	int maxProfits = 0;
	// Sliding window
	int start = 0, end = 1;
	if (prices.size() == 1) return 0;
	while (end != prices.size()) {
		int currentTransfer = prices[end] - prices[start];
		if (currentTransfer > maxProfits) {
			maxProfits = currentTransfer;
		}
		else if (currentTransfer <= 0) {
			start = end;
		}
		end++;
	}
	return maxProfits;
}


// Leetcode challenge 125
bool Solution::isPalindromeUpgrade(string s) {
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= '9' && s[i] >= '0')) {
			continue;
		}
		else {
			s.erase(s.begin() + i);
			i--;
		}
	}
	cout << "s= " << s << "\n";
	if (s.size() == 0) return true;
	for (int i = 0; i <= s.size() / 2; i++) {
		if (s[i] == s[s.size() - 1 - i] || s[i] == (s[s.size() - 1 - i] + 'a' - 'A') ||
			s[i] == (s[s.size() - 1 - i] + 'A' - 'a')) {
			if (s[i] <= '9' && s[i] >= '0')
			{
				if (s[i] == s[s.size() - 1 - i]) {
					continue;
				}
				else return false;
			}
			continue;
		}
		else return false;
	}
	return true;
}
// Leetcode challenge 217
bool Solution::containsDuplicate(vector<int>& nums) {
	set<int> st;
	for (int i = 0; i < nums.size(); i++) {
		if (st.count(nums[i]) != 1) {
			st.insert(nums[i]);
		}
		else {
			return true;
		}
	}
	return false;
}
// Leetcode challenge 560
int Solution::subarraySum(vector<int>& nums, int k) {
	// Biến đếm kết quả
	int result = 0;
	// Lưu lại các prefix vào 1 vector
	vector<int> prefix;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		prefix.push_back(sum);
	}
	map<int, int> mp;
	for (int i = 0; i < prefix.size(); i++) {
		if (prefix[i] == k) result++;
		if (mp.find(prefix[i] - k) != mp.end()) {
			result += mp[prefix[i] - k];
		}
		mp[prefix[i]] ++;
	}
	return result;
}

// Leetcode challenge 562
bool Solution::checkInclusion(string s1, string s2) {
	int a[26] = { 0 };
	for (int i = 0; i < s1.size(); i++) {
		a[s1[i] - 'a'] ++;
	}
	vector<vector<int>> s;
	for (int i = 0; i < 26; i++) {
		vector<int> temp;
		s.push_back(temp);
	}

	for (int i = 0; i < s2.size(); i++) {
		s[s2[i] - 'a'].push_back(i);
	}

	// Lấy các biến đếm của bên a so sánh với bên kia xem thử có đủ không
	// Push vào set tất cả các cái có thể để mà check thử xem nó có là chuỗi tăng liên tiếp
	
	// Làm một số cái giá trị chắc chắn có trước
	for (int i = 0; i < 26; i++) {
		
	}
	return false;

}


// Framework
void Solution::printVector(const vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << '\n';
}