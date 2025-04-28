#include <iostream>
#include "list.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int cnt = 0 ,global_cnt = 0, max_num, victim;
    LineList<int> list;
    list.insertFirst(1);
    cout<<"¬ведите количество людей: ";
    cin>>max_num;
    cout<<"¬ведите 'жертву': ";
    cin>>victim;
    LineListElem<int>* ptr = list.getStart();
    for(int i = 2; i < max_num + 1; i++)
    {
        list.insertAfter(ptr, i);
        ptr = ptr->getNext();
    }
    ptr = list.getStart();
    while (global_cnt != max_num - 1)
    {
        cnt++;
        if(cnt == victim - 1)
        {
            list.deleteAfter(ptr);
            global_cnt++;
            cnt = 0;
        }
        ptr = ptr->getNext();
    }
    cout<<list<<endl;
    return 0;
}
