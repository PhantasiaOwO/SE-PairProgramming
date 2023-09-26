#include "FileIOModule.h"

#include <fstream>
#include <sstream>

using namespace std;

void WriteExercisesToFile(const std::vector<Expression>& exercises) {
    ofstream file;
    file.open(ExercisesFileName, ios::out);
    for (size_t i = 0; i < exercises.size(); ++i) {
        file << i + 1 << '.' << exercises[i].GetString() << endl;
    }
    file.close();
}

void WriteAnswersToFile(const std::vector<Fraction>& results) {
    ofstream file;
    file.open(ExercisesFileName, ios::out);
    for (size_t i = 0; i < results.size(); ++i) {
        file << i + 1 << '.' << results[i] << endl;
    }
    file.close();
}

void ReadExercisesFromFile(const string fileName, std::vector<Expression>& outExpressions) {
    ifstream file;
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        cerr << L"无法打开文件" << fileName << L"！" << endl;
        return;
    }
    string buf;
    while (getline(file, buf)) {
        size_t pos = buf.find('.');
        string expression = buf.substr(pos + 1, buf.size() - pos - 1);
        outExpressions.emplace_back(expression);
    }
    file.close();
}

void ReadAnswersFromFile(const string fileName, std::vector<Fraction>& outFraction) {
    ifstream file;
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        cerr << L"无法打开文件" << fileName << L"！" << endl;
        return;
    }
    string buf;
    while (getline(file, buf)) {
        size_t pos = buf.find('.');
        string expression = buf.substr(pos + 1, buf.size() - pos - 1);
        stringstream ss(expression);
        Fraction f;
        ss >> f;
        outFraction.push_back(f);
    }
    file.close();
}
