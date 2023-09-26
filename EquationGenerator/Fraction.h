// https://www.cnblogs.com/gongkai/p/10806080.html
// 拱大垲原创
// 分数类实现~~~0.8.5
// fraction:分数 
// numerator:分子
// denominator:分母
// 输入分数时请以回车结尾
// 输入部分如含有空格，则空格后面的部分会被忽略 

#ifndef __FRACTION__
#define __FRACTION__

#include <iostream>
#include <cmath>

using namespace std;

namespace std {
    //分数类 
    class Fraction {
    private:
        int _num;
        int _den;

    public:
        // 获取两个数的最大公约数
        static int MCF(int a, int b);

        friend ostream& operator<<(ostream& os, const Fraction& f);

        friend istream& operator>>(istream& is, Fraction& f);

        friend Fraction operator+(const Fraction& f1, const Fraction& f2);

        friend Fraction operator-(const Fraction& f1, const Fraction& f2);

        friend Fraction operator*(const Fraction& f1, const Fraction& f2);

        friend Fraction operator/(const Fraction& f1, const Fraction& f2);

        friend Fraction operator+=(Fraction& f1, const Fraction& f2);

        friend Fraction operator-=(Fraction& f1, const Fraction& f2);

        friend Fraction operator*=(Fraction& f1, const Fraction& f2);

        friend Fraction operator/=(Fraction& f1, const Fraction& f2);

        friend Fraction operator-(const Fraction& f);

        friend Fraction operator++(Fraction& f);

        friend Fraction operator++(Fraction& f, int);

        friend Fraction operator--(Fraction& f);

        friend Fraction operator--(Fraction& f, int);

        friend bool operator>(const Fraction& f1, const Fraction& f2);

        friend bool operator<(const Fraction& f1, const Fraction& f2);

        friend bool operator>=(const Fraction& f1, const Fraction& f2);

        friend bool operator<=(const Fraction& f1, const Fraction& f2);

        friend bool operator==(const Fraction& f1, const Fraction& f2);

        friend bool operator!=(const Fraction& f1, const Fraction& f2);

        // 默认构造函数，为0
        Fraction();

        // 构造整数，分母为1
        Fraction(int num);

        // 传入整型的分子和分母构造分数
        Fraction(int num, int den);

        // 传入分数型的分子和分母构造分数
        Fraction(Fraction fNum, Fraction fDen);

        // 获取分数对应的浮点表示
        double Decimal()const ;

        // 获取分子
        int Num() const;

        // 获取分母
        int Den() const ;

        // 设置分子
        void Num(int num);

        // 设置分母
        void Den(int den);
    };
}

#endif // __FRACTION__
