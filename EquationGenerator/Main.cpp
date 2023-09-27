#include <iostream>
#include <string>

#include "Functions.h"

using namespace std;

int main(int argc, char* argv[]) {
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

    if (numsMax <= 0 || exerciseCount <= 0) {
        cerr << L"-r 和 -n 所接收的参数必须为大于0的自然数！" << endl;
    }
    if (exerciseCount > 0 && numsMax > 0 && exerciseFile.empty() && answerFile.empty()) {
        GenerateExpression(exerciseCount, numsMax);
    } else if (numsMax == 0 && exerciseCount == 0 && !exerciseFile.empty() && !answerFile.empty()) {
        bool canEnter = false;
        do {
            if (strrchr(exerciseFile.c_str(), '.') == nullptr) break; // 文件名中有 .
            if (strcmp(strrchr(exerciseFile.c_str(), '.'), "txt") != 0) break;  // 后缀为txt
            if (strrchr(answerFile.c_str(), '.') == nullptr) break;
            if (strcmp(strrchr(answerFile.c_str(), '.'), "txt") != 0) break;

            canEnter = true;
        } while (false);
        if (canEnter) {
            JudgeAnswers(exerciseFile, answerFile);
        } else cerr << L"文件字符串异常" << endl;
    } else {
        cerr << R"(参数异常，无法选择功能！
可能的原因：
判断题目参数-e -a没有同时出现
混用判断题目参数和生成题目参数)" << endl;
    }
    
    return 0;
}
