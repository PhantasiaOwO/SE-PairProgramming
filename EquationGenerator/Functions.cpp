#include "Functions.h"

#include <map>

#include "FileIOModule.h"

using namespace std;

void GenerateExpression(const int exerciseCount, const int maxRandomNum) {
    vector<Expression> expressions;
    vector<Fraction> answers;

    // 生成逻辑
    map<Fraction, vector<Expression*>> sameResultExpressionsMap;
    for (int i = 0; i < exerciseCount; ++i) {
        while (true) {
            Expression e(maxRandomNum, 2);
            auto& sameResultExp = sameResultExpressionsMap[e.GetResult()]; // 相同结果映射
            bool findSame = false;
            // 检查是否存在相同的算式
            for (const auto& exp : sameResultExp) {
                if (!(*exp == e)) continue;
                findSame = true;
                break; 
            }
            if (findSame) continue; // 找到相同的重新生成
            // 没找到就存起来
            expressions.push_back(e);
            sameResultExp.push_back(&expressions.back());
        }
    }

    // 答案向量构造
    answers.reserve(expressions.size());
    for (auto& expression : expressions) {
        answers.push_back(expression.GetResult());
    }

    // 输出到文件
    WriteExercisesToFile(expressions);
    WriteAnswersToFile(answers);
}

void JudgeAnswers(const std::string& exerciseFileName, const std::string& answersFileName) {
    vector<Expression> expressions;
    vector<Fraction> answers;

    // 文件读入
    ReadExercisesFromFile(exerciseFileName, expressions);
    ReadAnswersFromFile(answersFileName, answers);
    // 空的或者个数对不上不比较
    if (expressions.empty() || answers.empty() || expressions.size() != answers.size()) {
        cerr << R"(读取文件异常！
可能是文件中的习题或者答案列表为空，或者是习题文件与答案文件条目个数不匹配！)" << endl;
    }

    // 判断题目
    vector<int> correctLs;
    vector<int> wrongLs;
    int len = expressions.size();
    for (int i = 0; i < len; ++i) {
        if (expressions[i].GetResult() == answers[i]) correctLs.push_back(i + 1);
        else wrongLs.push_back(i);
    }

    // 写入文件
    WriteJudgeResultToFile(correctLs, wrongLs);
}
