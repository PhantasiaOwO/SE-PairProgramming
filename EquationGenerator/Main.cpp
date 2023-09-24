#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int exerciseCount = 0;
    int numsMax = 0;
    string exerciseFile;
    string answerFile;

    if ((argc & 1) == 0) cerr << L"输入的参数不合法" << endl;
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

    if (exerciseCount != 0 && numsMax != 0) {
        // TODO 生成题目分支
    } else if (!exerciseFile.empty() && !answerFile.empty()) {
        bool canEnter = false;
        do {
            if (strrchr(exerciseFile.c_str(), '.') == nullptr) break; // 文件名中有 .
            if (strcmp(strrchr(exerciseFile.c_str(), '.'), "txt") != 0) break;  // 后缀为txt
            if (strrchr(answerFile.c_str(), '.') == nullptr) break;
            if (strcmp(strrchr(answerFile.c_str(), '.'), "txt") != 0) break;

            canEnter = true;
        } while (false);
        if (canEnter) {
            // TODO 判断题目分支
        } else cerr << L"文件字符串异常" << endl;
    } else {
        cerr << L"参数异常，无法选择功能！" << endl;
    }

    return 0;
}
