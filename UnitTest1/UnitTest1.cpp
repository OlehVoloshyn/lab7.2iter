#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2 iter/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int k=100;
			const int n = 100;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			
			int s = 0;
			for (int j = 0; j < k; j++) {

				int min = a[j][0];

				for (int i = 0; i < n; i++)
				{
					if (a[j][i] < min)
						min = a[j][i];
				}
				s += min;
			}


			t = countEvenNumbers(a, k, n);
			Assert::AreEqual(t, s);
		}
	};
}
