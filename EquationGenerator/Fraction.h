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

        friend bool operator>(Fraction& f1, const Fraction& f2);

        friend bool operator<(Fraction& f1, const Fraction& f2);

        friend bool operator>=(Fraction& f1, const Fraction& f2);

        friend bool operator<=(Fraction& f1, const Fraction& f2);

        friend bool operator==(Fraction& f1, const Fraction& f2);

        friend bool operator!=(Fraction& f1, const Fraction& f2);

        Fraction();

        Fraction(int num);
        
        Fraction(int num, int den);

        Fraction(Fraction f1, Fraction f2);

        double Decimal();

        int GetNum();

        int GetDen();

        void SetNum(int num);

        void SetDen(int den);
    };
}

#endif // __FRACTION__
