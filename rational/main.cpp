#include <iostream>
#include <cmath>
#include "rational.h"
using namespace std;

int main()
{
    /*setlocale(LC_ALL, "Russian");
    Rational a, b, c, D, x1, x2;
    int check;
    cout<<"����� ��������� �� ������ ������? (�������� - 0, ���������� - 1): ";
    cin>>check;
    if(check == 0)
    {
        cout<<"��������� ������ � � ��������� ����, a*x + b = 0"<<endl;
        do
        {
            cout<<"������� ����� a (a != 0): ";
            cin>>a;
        }while(double(a) == 0);
        cout<<"������� ����� b: ";
        cin>>b;
        cout<<"x = "<<-b / a<<endl;
    }
    else if(check == 1)
    {
        cout<<"��������� ������ ����� � ��������� ����, a*x^2 + b*x + c = 0"<<endl;
        do
        {
            cout<<"������� ����� a (a != 0): ";
            cin>>a;
        }while(double(a) == 0);
        cout<<"������� ����� b: ";
        cin>>b;
        cout<<"������� ����� c: ";
        cin>>c;
        D = b * b - 4 * a * c;
        if((double)D < 0)
        {
            cout<<endl;
            cout<<"��� �������������� ������"<<endl;
        }
        else if((double)D == 0)
        {
            x1 = -b / (2 * a);
            cout<<endl;
            cout<<"����� ���������, ��� ��� ������������ ����� 0"<<endl;
            cout<<"�����: "<<x1<<" "<<x1<<endl;
        }
        else if((double)D > 0)
        {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            cout<<endl;
            cout<<"��������� ����� ��� �����"<<endl;
            cout<<"�����: "<<x1<<" "<<x2<<endl;
        }
    }*/
    Rational a, c;
    cout<<"Enter the number: ";
    cin>>a;
    cout<<a<<endl;
    c = sqrt(a);
    cout<<c<<endl;
    return 0;
}
