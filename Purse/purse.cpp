#include "purse.h"
#include <iostream>

using namespace std;

Purse& Purse::addMoney(Currency* c)
{
    string his;
    if (c != nullptr) {
        purse.push_back(c);
    }
    his = "Add " + to_string(c->getMoney()) + " " + c->name();
    history.push_back(his);
    return *this;
}

const vector<Currency*>& Purse::getContents() const {
    return purse;
}

double Purse::totalDollar(vector<Currency*> p)
{
    double total = 0.0;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i]->name() == "Dollar")
            total += p[i]->getMoney();
    }

    return total;
}

double Purse::totalEuro(vector<Currency*> p)
{
    double total = 0.0;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i]->name() == "Euro")
            total += p[i]->getMoney();
    }

    return total;
}

double Purse::totalPound(vector<Currency*> p)
{
    double total = 0.0;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i]->name() == "Pound")
            total += p[i]->getMoney();
    }

    return total;
}


double Purse::totalAmount(vector<Currency*> p)
{
    double total = 0.0;
    for(int i = 0; i < p.size(); i++)
        total += p[i]->transferToRubles();
    return total;
}

void Purse::print()
{
    for(int i = 0; i < history.size(); i++)
        cout<<history[i]<<endl;
}
