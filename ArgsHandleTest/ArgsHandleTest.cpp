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
			cerr << L"����Ĳ������Ϸ�" << endl;
			cerr << R"(֧�����²�����
-n <num> ���ɸ���
-r <num> ��������ֵ��ȡ������
-e <exercisefile>.txt ϰ���ļ�Ŀ¼
-a <answerfile>.txt ���ļ�Ŀ¼)" << endl;
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
				cerr << L"�������� " << type << L" ������" << endl;
			}
		}

		if (numsMax <= 0) {
			cerr << L"-r �����յĲ�������Ϊ����0����Ȼ����" << endl;
		}
		if (exerciseCount != 0 && numsMax > 0 && exerciseFile.empty() && answerFile.empty()) {
			return 1;
		} else if (numsMax == 0 && exerciseCount == 0 && !exerciseFile.empty() && !answerFile.empty()) {
			bool canEnter = false;
			do {
				if (strrchr(exerciseFile.c_str(), '.') == nullptr) break; // �ļ������� .
				if (strcmp(strrchr(exerciseFile.c_str(), '.') + 1, "txt") != 0) break;  // ��׺Ϊtxt
				if (strrchr(answerFile.c_str(), '.') == nullptr) break;
				if (strcmp(strrchr(answerFile.c_str(), '.') + 1, "txt") != 0) break;

				canEnter = true;
			} while (false);
			if (canEnter) {
				return 2;
			} else cerr << L"�ļ��ַ����쳣" << endl;
		} else {
			cerr << R"(�����쳣���޷�ѡ���ܣ�
���ܵ�ԭ��
�ж���Ŀ����-e -aû��ͬʱ����
�����ж���Ŀ������������Ŀ����)" << endl;
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
