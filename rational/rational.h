#ifndef _RATIONAL_H
#define _RATIONAL_H
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
class Error
{

};
class Rational
{
private:
    void simplify();
public:
    int numer, denom;
    Rational();
    Rational(int n);
    Rational(int n, int d);
    Rational& operator +=(const Rational& r);
    Rational operator +(const Rational& r) const;
    Rational operator - () const;
    Rational& operator -= (const Rational& r);
    Rational operator - (const Rational& r) const;
    Rational& operator *=(const Rational& r);
    Rational operator * (const Rational& r) const;
    Rational& operator *= (const int num);
    friend Rational operator*(const Rational& r, int num);
    friend Rational operator*(int num, const Rational& r);
    friend Rational operator / (const Rational& r, int num);
    friend Rational operator / (int num, const Rational& r);
    Rational& operator /= (const Rational& r);
    Rational operator / (const Rational& r) const;
    friend Rational sqrt(const Rational& r);
    friend Rational fabs(const Rational& r);
    Rational& operator ++ ();
    Rational operator ++(int);
    operator int() const;
    operator double() const;
    bool operator == (const Rational& r) const;
    bool operator != (const Rational& r) const;
    bool operator < (const Rational& r) const;
    bool operator >(const Rational& r) const;
    friend bool operator <(const Rational&r, int num);
    friend bool operator <(int num, const Rational&r);
    friend bool operator >(const Rational&r, int num);
    friend bool operator >(int num, const Rational&r);
    friend istream& operator >>(istream& in, Rational& r);
    friend ostream& operator <<(ostream& out, const Rational& r);
};
#endif
