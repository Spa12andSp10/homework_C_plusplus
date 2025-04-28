#include <iostream>
#include "linelist.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    LineList<int> list;
    cout<<"Start: "<<list<<endl;
    list.insertFirst(10);
    cout<<"Step 1: "<<list<<endl;
    LineListElem<int>* ptr = list.getStart();
    list.insertAfter(ptr, 15);
    cout<<"Step 2: "<<list<<endl;
    list.insertAfter(ptr->getNext(), 12);
    cout<<"Step 3: "<<list<<endl;
    list.insertFirst(7);
    cout<<"Step 4: "<<list<<endl;
    list.deleteFirst();
    cout<<"Step 5: "<<list<<endl;
    list.insertFirst(19);
    cout<<"Step 6: "<<list<<endl;
    list.insertAfter(ptr, 50);
    cout<<"Step 7: "<<list<<endl;
    list.deleteAfter(ptr->getNext()->getNext());
    cout<<"Step 8: "<<list<<endl;
    return 0;
}
