#include <iostream>
#include "Field.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Field field(true);
    while (!field.isOver())
    {
        field.print();
        cout<<"����� "<<(field.isRedTurnNow() ? "�������" : "������")<<
            " �����, ������� ��� (1-7)"<<endl;
        int column;
        cin>>column;
        field.makeTurn(column);
    }
    field.printResult();
    return 0;
}
