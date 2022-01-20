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
// Leetcode challenge 15

