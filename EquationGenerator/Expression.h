#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <string>

#include "Fraction.h"

class Expression {
    friend bool Equal(Expression& e1, Expression& e2);
    friend bool operator==(Expression& e1, Expression& e2);
private:

public:
    // 默认构造函数
    Expression();

    // 生成表达式 传入随机数的最大值和...
    Expression(int maxNum, int depth);
    
    // 将字符串表达式转换为数据结构
    explicit Expression(string& expression);

    // 获得字符串
    std::string GetString() const;

    // 获得表达式结果
    std::Fraction GetResult() const;
};
#endif // __EXPRESSION__
