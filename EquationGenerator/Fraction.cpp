#include "Fraction.h"

namespace std {
    int Fraction::MCF(int a, int b) {
        return a == 0 ? b : MCF(b % a, a);
    }

    ostream& operator<<(ostream& os, const Fraction& f) {
        const bool positive = f._num >= 0 && f._den >= 0 || f._num < 0 && f._den < 0;
        if (positive == false) os << "(-";
        if (f._den != 1) {
            if (abs(f._num) >= abs(f._den)) {
                os << abs(f._num) / abs(f._den) << "'" << abs(f._num) % abs(f._den) << "/" << abs(f._den);
            } else {
                os << abs(f._num) << "/" << abs(f._den);
            }
        } else os << abs(f._num);
        if (positive == false) os << ")";
        return os;
    }

    istream& operator>>(istream& is, Fraction& f) {
        char input[100];
        char ch;
        bool mid = false;
        bool is_pt = true;
        int integer = 0;
        f._num = f._den = 0;
        is >> input;
        for (int i = 0;; i++) {
            ch = input[i];
            if (ch == '\'') {
                integer = f._num;
                f._num = 0;
                continue;
            }
            if (ch == '-') {
                is_pt = !is_pt;
                continue;
            }
            if (ch == '/') {
                mid = true;
                continue;
            }
            if (ch < '0' || ch > '9') break;
            if (mid == false) f._num = f._num * 10 + (ch - '0');
            else f._den = f._den * 10 + (ch - '0');
        }
        if (mid == false) f._den = 1;
        if (f._den == 0) {
            cerr << L"不允许分母为0！" << endl;
            return is;
        }
        f._num += integer * f._den;
        int mcf = Fraction::MCF(f._num, f._den);
        f._num /= mcf;
        f._den /= mcf;
        if (!is_pt) f._num = -f._num;
        return is;
    }

    Fraction operator+(const Fraction& f1, const Fraction& f2) {
        int num = f1._num * f2._den + f2._num * f1._den;
        int den = f1._den * f2._den;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& f1, const Fraction& f2) {
        int num = f1._num * f2._den - f2._num * f1._den;
        int den = f1._den * f2._den;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& f1, const Fraction& f2) {
        int num = f1._num * f2._num;
        int den = f1._den * f2._den;
        int mcf = Fraction::MCF(num, den);
        num /= mcf;
        den /= mcf;
        Fraction fraction(num, den);
        return fraction;
    }

    Fraction operator/(const Fraction& f1, const Fraction& f2) {
        return f1 * Fraction(f2._den, f2._num);
    }

    Fraction operator+=(Fraction& f1, const Fraction& f2) {
        return f1 = f1 + f2;
    }

    Fraction operator-=(Fraction& f1, const Fraction& f2) {
        return f1 = f1 - f2;
    }

    Fraction operator*=(Fraction& f1, const Fraction& f2) {
        return f1 = f1 * f2;
    }

    Fraction operator/=(Fraction& f1, const Fraction& f2) {
        return f1 = f1 / f2;
    }

    Fraction operator-(const Fraction& f) {
        return 0 - f;
    }

    Fraction operator++(Fraction& f) {
        f = f + 1;
        return f;
    }

    Fraction operator++(Fraction& f, int) {
        f = f + 1;
        return f - 1;
    }

    Fraction operator--(Fraction& f) {
        f = f - 1;
        return f;
    }

    Fraction operator--(Fraction& f, int) {
        f = f - 1;
        return f + 1;
    }

    bool operator>(const Fraction& f1, const Fraction& f2) {
        return f1._num * f2._den > f2._num * f1._den;
    }

    bool operator<(const Fraction& f1, const Fraction& f2) {
        return f1._num * f2._den < f2._num * f1._den;
    }

    bool operator>=(const Fraction& f1, const Fraction& f2) {
        return f1._num * f2._den >= f2._num * f1._den;
    }

    bool operator<=(const Fraction& f1, const Fraction& f2) {
        return f1._num * f2._den <= f2._num * f1._den;
    }

    bool operator==(const Fraction& f1, const Fraction& f2) {
        return f1._num * f2._den == f2._num * f1._den;
    }

    bool operator!=(const Fraction& f1, const Fraction& f2) {
        return f1._num * f2._den != f2._num * f1._den;
    }

    Fraction::Fraction() {
        _num = 0;
        _den = 1;
    }

    Fraction::Fraction(int num) {
        _num = num;
        _den = 1;
    }

    Fraction::Fraction(int num, int den) {
        int mcf = Fraction::MCF(num, den);
        _num = num / mcf;
        _den = den / mcf;
    }

    Fraction::Fraction(Fraction fNum, Fraction fDen) {
        int num = fNum._num * fDen._den;
        int den = fNum._den * fDen._num;
        int mcf = Fraction::MCF(num, den);
        _num = num / mcf;
        _den = den / mcf;
    }

    double Fraction::Decimal() const {
        return 1.0 * _num / _den;
    }

    int Fraction::Num() const {
        return _num;
    }

    int Fraction::Den() const {
        return _den;
    }

    void Fraction::Num(int num) {
        _num = num;
        int mcf = Fraction::MCF(_num, _den);
        _num /= mcf;
        _den /= mcf;
    }

    void Fraction::Den(int den) {
        if (den != 0) {
            _den = den;
            int mcf = Fraction::MCF(_num, _den);
            _num /= mcf;
            _den /= mcf;
        } else {
            cerr << L"不允许分母为0！" << endl;
        }
    }
}
