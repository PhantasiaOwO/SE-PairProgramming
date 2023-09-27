#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ExpressionTest {
	TEST_CLASS(ExpressionEqualTest) {
	public:
		TEST_METHOD(EqualTest0) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest1) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest2) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest3) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest4) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest5) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest6) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest7) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest8) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}

		TEST_METHOD(EqualTest9) {
			string expString1("1 + 1 + 1 + 1");
			string expString2("1 + 1 + 1 + 1");
			Expression exp1(expString1);
			Expression exp2(expString2);
			Assert::IsTrue(exp1 == exp2);
		}
	};
}
