#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FractionTest {
	TEST_CLASS(FractionInputStreamTest) {
	public:
		TEST_METHOD(TestMethod1) {
			Fraction f(1, 2);
			stringstream ss;
			ss << f;
			Assert::AreEqual(ss.str(), string("1/2"));
		}

		TEST_METHOD(TestMethod2) {
			Fraction f(2, 2);
			stringstream ss;
			ss << f;
			Assert::AreEqual(ss.str(), string("1"));
		}

		TEST_METHOD(TestMethod3) {
			Fraction f(3, 2);
			stringstream ss;
			ss << f;
			Assert::AreEqual(ss.str(), string("1'1/2"));
		}

		TEST_METHOD(TestMethod4) {
			Fraction f(0, 5);
			stringstream ss;
			ss << f;
			Assert::AreEqual(ss.str(), string("0"));
		}

		TEST_METHOD(TestMethod5) {
			Fraction f(3, 9);
			stringstream ss;
			ss << f;
			Assert::AreEqual(ss.str(), string("1/3"));
		}

		TEST_METHOD(TestMethod6) {
			Fraction f(17, 4);
			stringstream ss;
			ss << f;
			Assert::AreEqual(ss.str(), string("4'1/4"));
		}
	};

	TEST_CLASS(FractionOutputStreamTest) {
	public:
		TEST_METHOD(TestMethod1) {
			Fraction f;
			stringstream ss;
			ss << "0";
			ss >> f;
			Assert::IsTrue(f == Fraction(0, 1));
		}

		TEST_METHOD(TestMethod2) {
			Fraction f;
			stringstream ss;
			ss << "1";
			ss >> f;
			Assert::IsTrue(f == Fraction(1, 1));
		}

		TEST_METHOD(TestMethod3) {
			Fraction f;
			stringstream ss;
			ss << "1/2";
			ss >> f;
			Assert::IsTrue(f == Fraction(1, 2));
		}

		TEST_METHOD(TestMethod4) {
			Fraction f;
			stringstream ss;
			ss << "1'1/2";
			ss >> f;
			Assert::IsTrue(f == Fraction(3, 2));
		}

		TEST_METHOD(TestMethod5) {
			Fraction f;
			stringstream ss;
			ss << "1'2/3";
			ss >> f;
			Assert::IsTrue(f == Fraction(5, 3));
		}

		TEST_METHOD(TestMethod6) {
			Fraction f;
			stringstream ss;
			ss << "3'1/5";
			ss >> f;
			Assert::IsTrue(f == Fraction(16, 5));
		}
	};
}
