#include <iostream>
#include <vector>
#include "money.h"
#include "purse.h"

using namespace std;

int main()
{
    Purse purse;
    Currency* c1 = new Euro(12.45);
    Currency* c2 = new Dollar();
    Currency* c3 = new Pound(100.0);
    purse.addMoney(c1);
    purse.addMoney(c2);
    purse.addMoney(c3);
    vector<Currency*> pur = purse.getContents();
    double t = purse.totalAmount(pur);
    purse.print();
    cout<<t<<endl;
    return 0;
}
