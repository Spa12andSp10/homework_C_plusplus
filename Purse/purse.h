#ifndef _PURSE_H
#define _PURSE_H

#include <iostream>
#include <vector>
#include "money.h"

using namespace std;

class Purse
{
private:
    vector<Currency*> purse;
    vector<string> history;
public:
    Purse& addMoney(Currency* c);
    const vector<Currency*>& getContents() const;
    double totalDollar(vector<Currency*> p);
    double totalEuro(vector<Currency*> p);
    double totalPound(vector<Currency*> p);
    double totalAmount(vector<Currency*> p);
    void print();
};

#endif
