#include "rational.h"
#include <cmath>
using namespace std;

Rational::Rational()
{
    numer = 0;
    denom = 1;
}

Rational::Rational(int number)
{
    numer = number;
    denom = 1;
}

Rational::Rational(int n, int d)
{
    numer = n;
    denom = d;
    simplify();
}

Rational& Rational::operator +=(const Rational& r)
{
    numer = (numer*r.denom+denom*r.numer);
    denom *= r.denom;
    simplify();
    return *this;
}

void Rational::simplify()
{
    int a = abs(numer);
    int b = abs(denom);
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    numer /= a;
    denom /= a;
}


Rational Rational::operator +(const Rational &r) const
{
    Rational res(*this);
    return res += r;
}

Rational Rational::operator - () const
{
    Rational r(-numer, denom);
    return r;
}

Rational& Rational::operator-=(const Rational& r)
{
    return (*this += (-r));
}

Rational Rational::operator-(const Rational& r) const
{
    Rational res(*this);
    return res -= r;
}

Rational& Rational::operator*=(const Rational& r)
{
    numer *= r.numer;
    denom *= r.denom;
    simplify();
    return *this;
}

Rational Rational::operator*(const Rational& r) const
{
    Rational res(*this);
    return res *= r;
}

Rational& Rational::operator *= (const int num)
{
    numer *= num;
    simplify();
    return *this;
}

Rational operator*(const Rational& r, int num) {
    Rational res(r);
    return res *= num;
}

Rational operator*(int num, const Rational& r) {
    return r * num;
}

Rational operator /(const Rational& r, int num) {
    Rational res(r);
    return res /= num;
}

Rational operator /(int num, const Rational& r) {
    return r / num;
}

Rational& Rational::operator /= (const Rational& r)
{
    numer *= r.denom;
    denom *= r.numer;
    simplify();
    return *this;
}

Rational Rational::operator / (const Rational& r) const
{
    Rational res(*this);
    return res /= r;
}

Rational sqrt(const Rational& r)
{
    if(r < 0)
        throw Error();
    Rational start(r), x(r), a(1, 2), epsilon(1, 1E6);
    Rational nextX;
    while(true)
    {
        Rational res = start / x;
        Rational res2 = x + res;
        if(a.numer > INT_MAX/res2.numer || a.denom > INT_MAX/res2.denom)
        {
            return x;
            break;
        }
        nextX = a * res2;
        if(fabs(nextX - x) < epsilon)
            break;
        x = nextX;
    }
    return x;
}

Rational fabs(const Rational& r)
{
    Rational res(r);
    if(res > 0)
        return res;
    else if(res < 0)
        return res * -1;
}

Rational& Rational::operator ++()
{
    numer += denom;
    return *this;
}

Rational Rational::operator ++(int)
{
    Rational r(*this);
    numer += denom;
    return r;
}

bool Rational::operator ==(const Rational& r) const
{
    return (numer == r.numer && denom == r.denom);
}

bool Rational::operator !=(const Rational& r) const
{
    return !(*this == r);
}

bool Rational::operator <(const Rational& r) const
{
    return (numer * r.denom < r.numer * denom);
}

bool Rational::operator >(const Rational& r) const
{
    return !(*this < r);
}

bool operator <(const Rational&r, int num)
{
    Rational newNum(num);
    return r < newNum;
}

bool operator <(int num, const Rational&r)
{
    Rational newNum(num);
    return newNum < r;
}

bool operator >(const Rational&r, int num)
{
    Rational newNum(num);
    return r > newNum;
}

bool operator >(int num, const Rational&r)
{
    Rational newNum(num);
    return newNum > r;
}

Rational::operator int() const
{
    return numer / denom;
}

Rational::operator double() const
{
    return ((double)numer) / denom;
}

istream& operator >>(istream& in, Rational& r)
{
    in>>r.numer>>r.denom;
    return in;
}

ostream& operator <<(ostream& out, const Rational& r)
{
    out<<r.numer<<"/"<<r.denom;
    return out;
}
