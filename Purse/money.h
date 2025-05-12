#ifndef _MONEY_H
#define _MONEY_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Error
{

};

class Currency
{
public:
    virtual string name() = 0;
    virtual double getRate() = 0;
    virtual double getMoney() = 0;
    virtual void setRate(double newRate) = 0;
    virtual double transferToRubles() = 0;
    virtual double transferToNational() = 0;
};

class Dollar : public Currency
{
private:
    double money, rate = 80.86;
public:
    Dollar();
    Dollar(double amoney);
    string name();
    double getRate();
    double getMoney();
    void setRate(double newRate);
    double transferToRubles();
    double transferToNational();
    friend ostream& operator<<(ostream& os, const Dollar& d);
};

class Euro : public Currency
{
private:
    double money, rate = 92.14;
public:
    Euro();
    Euro(double amoney);
    string name();
    double getRate();
    double getMoney();
    void setRate(double newRate);
    double transferToRubles();
    double transferToNational();
    friend ostream& operator<<(ostream& os, const Euro& e);
};

class Pound : public Currency
{
private:
    double money, rate = 108.13;
public:
    Pound();
    Pound(double amoney);
    string name();
    double getRate();
    double getMoney();
    void setRate(double newRate);
    double transferToRubles();
    double transferToNational();
    friend ostream& operator<<(ostream& os, const Pound & p);
};

#endif
