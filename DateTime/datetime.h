#ifndef _DATETIME_H
#define _DATETIME_H
#include <iostream>
#include <fstream>

using namespace std;

const int LENDATE = 10;

class Date
{
public:
    int day, month, year;
    Date();
    Date(int d);
    Date(int d, int m);
    Date(int d, int m, int y);
    Date& operator += (int days);
    Date operator+(int days);
    Date& operator -=(int days);
    Date operator -(int days);
    Date& operator -= (const Date& d);
    Date operator -(const Date& d);
    int JulianDate(const Date& r);
    Date GrigDate(int JDN);
    int DifferenceInDates(const Date& d, const Date& ad);
    friend istream& operator >>(istream& in, Date& r);
    friend ostream& operator <<(ostream& out, const Date& r);
};
#endif
