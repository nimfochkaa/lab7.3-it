#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3 2 іт/7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My73
{
	TEST_CLASS(My73)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int row1[] = { 1, -2, 3 };
			int row2[] = { 4, 5, 6 };
			int row3[] = { -7, 8, -9 };

			int* a[] = { row1, row2, row3 };

			int sum = CalculateSumOfRowsWithNegatives(a, rowCount, colCount);

			Assert::AreEqual(-6, sum, L"Incorrect sum of rows with negatives");
		}
	};
}
