#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\lizas\Desktop\git\Main\Main\Main.cpp" 
#include <expected> 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests

{
	//Unit tests for Calculate function
	TEST_CLASS(calculate_Tests)
	{

	public:
		TEST_METHOD(calculate_get9and2and4and3_14returned)
		{
			double from = 2;
			double to = 4;
			double step = 3;
			int n = 9;
			int expected = 14;
			double x = from;
			int actual = calculate(from, to, step, x, n);
			Assert::AreEqual(expected, actual);
		}

	public:

		TEST_METHOD(calculate_get3and8and6and9_7returned)

		{
			double from = 3;
			double to = 8;
			double step = 6;
			int n = 9;
			int expected = 7;
			double x = from;
			int actual = calculate(from, to, step, x, n);
			Assert::AreEqual(expected, actual);
		}

	};


	//Unit tests for checkValidParams function
	TEST_CLASS(checkValidParams_Tests)

	{

	public:

		TEST_METHOD(checkValidParams_get10_exceptionNotThrown)

		{
			double from = 4;
			double to = 9;
			double step = 2;
			int n = 10;



			try

			{
				checkValidParams(from, to, step, n);
				Assert::IsTrue(true);
			}

			catch (...)

			{
				Assert::Fail();

			}

		}

	public:

		TEST_METHOD(checkValidParams_get2_exceptionThrown)

		{

			double from = 3;
			double to = 5;
			double step = 2;
			int n = 2;

			try

			{

				checkValidParams(from, to, step, n);
				Assert::Fail();

			}

			catch (...)

			{

				Assert::IsTrue(true);

			}

		}

	};

}

