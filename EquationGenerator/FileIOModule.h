#ifndef __FILEIOMODULE__
#define __FILEIOMODULE__

#include <vector>
#include <string>

#include "Expression.h"

const std::string MultiplySign = "×";
const std::string DivideSign = "÷";
const std::string ExercisesFileName = "Exercises.txt";
const std::string AnswersFileName = "Answers.txt";

void WriteExercisesToFile(const std::vector<Expression>& exercises);
void WriteAnswersToFile(const std::vector<Fraction>& results);
void ReadExercisesFromFile(const string fileName, std::vector<Expression>& outExpressions);
void ReadAnswersFromFile(const string fileName, std::vector<Fraction>& outFraction);

#endif // __FILEIOMODULE__