#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1 rec/8.1 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
	TEST_CLASS(UnitTest81rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{// Тестовий рядок із чотирма крапками
			char testStr1[] = "Hello...world....";
			int position1 = FindFourthDot(testStr1, strlen(testStr1) - 1, 0);
			Assert::AreEqual(13, position1);
		}
	};
}
