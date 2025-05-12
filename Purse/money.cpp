#include "money.h"
#include <iostream>

using namespace std;

Dollar::Dollar()
{
    money = 1.0;
}

Dollar::Dollar(double amoney)
{
    money = amoney;
}

string Dollar::name()
{
    return "Dollar";
}

double Dollar::getRate()
{
    return rate;
}

double Dollar::getMoney()
{
    return money;
}

void Dollar::setRate(double newRate)
{
    if(newRate <= 0)
        throw Error();
    rate = newRate;
}

double Dollar::transferToRubles()
{
    return money * rate;
}

double Dollar::transferToNational()
{
    return money * 100;
}

ostream& operator<<(ostream& out, const Dollar& d)
{
    out<<d.money<<" dollars (rate: " << d.rate << ")";
    return out;
}

Euro::Euro()
{
    money = 1.0;
}

Euro::Euro(double amoney)
{
    money = amoney;
}

string Euro::name()
{
    return "Euro";
}

double Euro::getRate()
{
    return rate;
}

double Euro::getMoney()
{
    return money;
}


void Euro::setRate(double newRate)
{
    if(newRate <= 0)
        throw Error();
    rate = newRate;
}

double Euro::transferToRubles()
{
    return money * rate;
}

double Euro::transferToNational()
{
    return money * 100;
}

ostream& operator<<(ostream& out, const Euro& e)
{
    out<<e.money<<" euro (rate: " << e.rate << ")";
    return out;
}

Pound::Pound()
{
    money = 1.0;
}

Pound::Pound(double amoney)
{
    money = amoney;
}

string Pound::name()
{
    return "Pound";
}

double Pound::getRate()
{
    return rate;
}

double Pound::getMoney()
{
    return money;
}

void Pound::setRate(double newRate)
{
    if(newRate <= 0)
        throw Error();
    rate = newRate;
}

double Pound::transferToRubles()
{
    return money * rate;
}

double Pound::transferToNational()
{
    return money * 100;
}

ostream& operator<<(ostream& out, const Pound& p)
{
    out<<p.money<<" pound (rate: " << p.rate << ")";
    return out;
}
