#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ExpressionTest {
	TEST_CLASS(ExpressionEqualTest) {
	public:
		TEST_METHOD(ConvertionTest0) {
			string expString("1 + 1 + 1 + 1");
			Fraction result(4);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest1) {
			string expString("1 ¡Á 1 + 1 + 1");
			Fraction result(3);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest2) {
			string expString("1 ¡Â 1 + 1 ¡Â 1");
			Fraction result(2);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest3) {
			string expString("( 1 + 1 ) ¡Á ( 1 + 1 )");
			Fraction result(4);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest4) {
			string expString("5 + 6 + 7 ¡Á 1");
			Fraction result(18);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest5) {
			string expString("1 + 1 + 1 + 1");
			Fraction result(4);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest6) {
			string expString("1 + 1 + 1 + 1");
			Fraction result(4);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest7) {
			string expString("1 + 1 + 1 + 1");
			Fraction result(4);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest8) {
			string expString("1 + 1 + 1 + 1");
			Fraction result(4);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}

		TEST_METHOD(ConvertionTest9) {
			string expString("1 + 1 + 1 + 1");
			Fraction result(4);
			Expression exp(expString);
			Assert::AreEqual(expString, exp.GetString());
			Fraction f;
			stringstream ss;
			ss >> f;
			Assert::IsTrue(f == exp.GetResult());
		}
	};
}
