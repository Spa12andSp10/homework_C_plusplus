#include <iostream>
#include "datetime.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Date userDate, anUserDate;
    int t, i;
    cout<<"������� ���� � ������� (�� �� ����): ";
    cin>>userDate;
    cout<<"������� ������ ����, ������� ��� ������ ���������� � ������� (�� �� ����): ";
    cin>>anUserDate;
    cout<<"������� ����� ���������� ���� ";
    cin>>t;
    Date res = userDate + t;
    cout<<"����� "<<t<<" ���� ����� ��� ����� "<<res<<endl;
    res = userDate - t;
    cout<<"���� "<<res<<" ����� "<<t<<" �����"<<endl;\
    i = userDate.DifferenceInDates(userDate, anUserDate);
    if(i != -1)
        cout<<"���������� ���� �� "<<anUserDate<<" ����� "<<i<<endl;
    else
        cout<<"���� "<<anUserDate<<" ������ ��� ���� "<<userDate<<endl;
    return 0;
}
