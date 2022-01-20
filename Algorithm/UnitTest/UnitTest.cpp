#include "pch.h"
#include "CppUnitTest.h"
#include "../Algorithm/Solution.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest
{
	TEST_CLASS(intToRoman)
	{
	public:
		TEST_METHOD(TestA)
		{
			string input = "V";
			Solution solution;
			Assert::AreEqual(5, solution.romanToInt(input));
		}

		TEST_METHOD(TestB)
		{
			string input = "VI";
			Solution solution;
			Assert::AreEqual(8, solution.romanToInt(input));
		}
	};
}
