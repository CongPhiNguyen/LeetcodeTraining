#include <iostream>;
#include <string>

using namespace std;

#pragma once
class Solution
{
public:
	// Leetcode challenge 13
	int romanToInt(string s)
	{
		int result = 0;
		string pattern[6] = { "IV", "IX", "XL", "XC", "CD", "CM" };
		int value[6] = { 4, 9, 40, 90, 400, 900 };
		for (int i = 0; i < 6; i++)
		{
			int findValue = s.find(pattern[i]);
			if ( findValue!= -1)
			{
				result += value[i];
				s = s.replace(findValue, 2, "");
			}
		}
		string basicPatterns[7] = {"I", "V", "X", "L", "C", "D", "M"};
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
};

