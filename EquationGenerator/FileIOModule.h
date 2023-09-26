#ifndef __FILEIOMODULE__
#define __FILEIOMODULE__

#include <vector>
#include <string>

#include "Expression.h"

const std::string MultiplySign = "×";
const std::string DivideSign = "÷";
const std::string ExercisesFileName = "Exercises.txt";
const std::string AnswersFileName = "Answers.txt";
const std::string GradeFileName = "Grade.txt";

// 向文件写入习题列表，传入参数：习题列表
void WriteExercisesToFile(const std::vector<Expression>& exercises);
// 向文件写入答案列表，传入参数：习题列表
void WriteAnswersToFile(const std::vector<Fraction>& results);
// 从文件读取习题列表，传入参数：文件名称、习题列表引用
void ReadExercisesFromFile(const std::string& fileName, std::vector<Expression>& outExpressions);
// 从文件读取答案列表，传入参数：文件名称、习题列表引用
void ReadAnswersFromFile(const std::string& fileName, std::vector<Fraction>& outFraction);
// 写入判定结果文件
void WriteJudgeResultToFile(const std::string, std::vector<int>& correctList,std::vector<int>& wrongList);

#endif // __FILEIOMODULE__