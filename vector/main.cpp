#include <iostream>
#include <ctime>
#include "array.h"
using namespace std;

const int SIZE = 1000;

int main()
{
    setlocale(LC_ALL, "Russian");
    time_t now;
    time(&now);
    cout<<now<<endl;
    Array arr(SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        try
        {
            arr.insert(i + 1);
        }catch(ArrayException)
        {
            cout<<"Error!"<<endl;
        }
    }
    int index = 0;

    while (arr.getSize() > 1)
    {
        index = (index + 1) % arr.getSize();
        try
        {
            arr.remove(index);
        }catch(ArrayException)
        {
            cout<<"Error!"<<endl;
        }
    }

    cout << arr << endl;
    time(&now);
    cout<<now<<endl;
    /*Array arr(20);
    for (int i=0; i<4; i++)
    {
        try
        {
           arr.insert(i+1);
        }catch(ArrayException)
        {
            cout<<"Error!"<<endl;
        }
    }
    cout<<arr<<endl;
    for (int i=0; i<8; i+=2)
    {
        try
        {
            arr.insert(10+i,i);
        }catch(ArrayException)
        {
            cout<<"Error!"<<endl;
        }
    }

    cout<<arr<<endl;
    for (int i=1; i<8; i+=2)
    {
        try
        {
            arr[i]=20+i;
        }catch(ArrayException)
        {
            cout<<"Error!"<<endl;
        }
    }

    cout<<arr<<endl;
    for (int i=6; i>=0; i-=3)
    {
        try
        {
            arr.remove(i);
        }catch(ArrayException)
        {
            cout<<"Error!"<<endl;
        }
    }

    cout<<arr<<endl;
    Array arr2(10);
    for(int i = 0; i < 10; i++)
    {
        try
        {
            arr2.insert(-20-i);
        }catch(ArrayException)
        {
            cout<<"Error!"<<endl;
        }
    }

    try
    {
       arr.insert(arr2, 5);
    }catch(ArrayException)
    {
        cout<<"Error!"<<endl;
    }
    cout<<arr<<endl;*/
    return 0;
}
