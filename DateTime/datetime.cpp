#include "datetime.h"
#include <iostream>
#include <fstream>
using namespace std;

Date::Date()
{
    day = 1;
    month = 1;
    year = 1;
}

Date::Date(int d)
{
    day = d;
    month = 1;
    year = 1;
}

Date::Date(int d, int m)
{
    day = d;
    month = m;
    year = 1;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

istream& operator >>(istream& in, Date& r)
{
    in>>r.day>>r.month>>r.year;
    return in;
}


ostream& operator <<(ostream& out, const Date& r)
{
    out<<r.day<<"."<<r.month<<"."<<r.year;
    return out;
}

int Date::JulianDate(const Date& r) {
    int a = (14 - r.month) / 12;
    int y1 = r.year + 4800 - a;
    int m1 = r.month + 12 * a - 3;
    int JDN = r.day + (153 * m1 + 2) / 5 + 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 - 32045;
    return JDN;
}

Date Date::GrigDate(int JDN) {
    int a, b, c, d, e, m1, day1, month1, year1;
    a = JDN + 32044;
    b = (4 * a + 3) / 146097;
    c = a - (146097 * b) / 4;
    d = (4 * c + 3) / 1461;
    e = c - (1461 * d) / 4;
    m1 = (5 * e + 2) / 153;
    day1 = e - (153 * m1 + 2) / 5 + 1;
    month1 = m1 + 3 - 12 * (m1 / 10);
    year1 = 100 * b + d - 4800 + (m1 / 10);
    return Date(day1, month1, year1);
}

Date& Date::operator += (int days) {
    Date r(*this);
    int julianDayNumber = JulianDate(r);
    julianDayNumber += days;
    *this = GrigDate(julianDayNumber);
    return *this;
}

Date Date::operator+(int days)
{
    Date res(*this);
    return res += days;
}

Date& Date::operator -=(int days)
{
    Date r(*this);
    int julianDayNumber = JulianDate(r);
    julianDayNumber -= days;
    *this = GrigDate(julianDayNumber);
    return *this;
}

Date Date::operator -(int days)
{
    Date res(*this);
    return res -= days;
}

Date& Date::operator -= (const Date& d)
{
    day -= d.day;
    month -= d.month;
    year -= d.year;
    day = abs(day);
    month = abs(month);
    year = abs(year);
    return *this;
}

Date Date::operator - (const Date& d)
{
    Date r(*this);
    return r -= d;
}

int Date::DifferenceInDates(const Date& d, const Date& ad)
{
    int julOne = JulianDate(d);
    int julTwo = JulianDate(ad);
    if(julTwo < julOne)
        return -1;
    else
        return julTwo - julOne;
}

