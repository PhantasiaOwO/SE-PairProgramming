#include "pch.h"

#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ArgsHandleTest {
	int OriginMain(int argc, char* argv[]) {
		int exerciseCount = 0;
		int numsMax = 0;
		string exerciseFile;
		string answerFile;

		if ((argc & 1) == 0) {
			cerr << L"输入的参数不合法" << endl;
			cerr << R"(支持如下参数：
-n <num> 生成个数
-r <num> 随机数最大值（取不到）
-e <exercisefile>.txt 习题文件目录
-a <answerfile>.txt 答案文件目录)" << endl;
			return 0;
		}
		for (int i = 1; i + 1 < argc; i += 2) {
			string type(argv[i]);
			string param(argv[i + 1]);
			if (type == "-n") {
				exerciseCount = stoi(param);
			} else if (type == "-r") {
				numsMax = stoi(param);
			} else if (type == "-e") {
				exerciseFile = param;
			} else if (type == "-a") {
				answerFile = param;
			} else {
				cerr << L"参数类型 " << type << L" 不合理！" << endl;
			}
		}

		if (numsMax <= 0) {
			cerr << L"-r 所接收的参数必须为大于0的自然数！" << endl;
		}
		if (exerciseCount != 0 && numsMax > 0 && exerciseFile.empty() && answerFile.empty()) {
			return 1;
		} else if (numsMax == 0 && exerciseCount == 0 && !exerciseFile.empty() && !answerFile.empty()) {
			bool canEnter = false;
			do {
				if (strrchr(exerciseFile.c_str(), '.') == nullptr) break; // 文件名中有 .
				if (strcmp(strrchr(exerciseFile.c_str(), '.') + 1, "txt") != 0) break;  // 后缀为txt
				if (strrchr(answerFile.c_str(), '.') == nullptr) break;
				if (strcmp(strrchr(answerFile.c_str(), '.') + 1, "txt") != 0) break;

				canEnter = true;
			} while (false);
			if (canEnter) {
				return 2;
			} else cerr << L"文件字符串异常" << endl;
		} else {
			cerr << R"(参数异常，无法选择功能！
可能的原因：
判断题目参数-e -a没有同时出现
混用判断题目参数和生成题目参数)" << endl;
		}
		return 0;
	}

	TEST_CLASS(ArgsHandleTest) {
	public:
		TEST_METHOD(TestMethod1) {
			int argc = 1;
			char* argv[]{"exe"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(0 ,ret);
		}

		TEST_METHOD(TestMethod2) {
			int argc = 3;
			char* argv[]{"exe", "-n", "10"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(0, ret);
		}

		TEST_METHOD(TestMethod3) {
			int argc = 5;
			char* argv[]{"exe", "-n", "10", "-r", "10"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(1, ret);
		}

		TEST_METHOD(TestMethod4) {
			int argc = 5;
			char* argv[]{"exe", "-r", "10", "-n", "10"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(1, ret);
		}

		TEST_METHOD(TestMethod5) {
			int argc = 3;
			char* argv[]{"exe", "-e", "111.txt"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(0, ret);
		}

		TEST_METHOD(TestMethod6) {
			int argc = 3;
			char* argv[]{"exe", "-a", "111.txt"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(0, ret);
		}

		TEST_METHOD(TestMethod7) {
			int argc = 5;
			char* argv[]{"exe", "-e", "111.txt", "-a", "111.txt"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(2, ret);
		}

		TEST_METHOD(TestMethod8) {
			int argc = 5;
			char* argv[]{"exe", "-a", "111.txt", "-e", "111.txt"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(2, ret);
		}

		TEST_METHOD(TestMethod9) {
			int argc = 9;
			char* argv[]{"exe", "-a", "111.txt", "-e", "111.txt", "-r", "10", "-n", "10"};
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(0, ret);
		}

		TEST_METHOD(TestMethod10) {
			int argc = 7;
			char* argv[]{ "exe", "-a", "111.txt", "-r", "10", "-n", "10" };
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(0, ret);
		}

		TEST_METHOD(TestMethod11) {
			int argc = 5;
			char* argv[]{ "exe", "-a", "111.txt", "-n", "10" };
			int ret = OriginMain(argc, argv);
			Assert::AreEqual(0, ret);
		}
	};
}
