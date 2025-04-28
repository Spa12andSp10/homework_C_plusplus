#include <iostream>
#include <cmath>
#include "rational.h"
using namespace std;

int main()
{
    /*setlocale(LC_ALL, "Russian");
    Rational a, b, c, D, x1, x2;
    int check;
    cout<<"Какое уравнение вы хотите решить? (линейное - 0, квадратное - 1): ";
    cin>>check;
    if(check == 0)
    {
        cout<<"Программа найдет х в уравнении вида, a*x + b = 0"<<endl;
        do
        {
            cout<<"Введите число a (a != 0): ";
            cin>>a;
        }while(double(a) == 0);
        cout<<"Введите число b: ";
        cin>>b;
        cout<<"x = "<<-b / a<<endl;
    }
    else if(check == 1)
    {
        cout<<"Программа найдет корни в уравнении вида, a*x^2 + b*x + c = 0"<<endl;
        do
        {
            cout<<"Введите число a (a != 0): ";
            cin>>a;
        }while(double(a) == 0);
        cout<<"Введите число b: ";
        cin>>b;
        cout<<"Введите число c: ";
        cin>>c;
        D = b * b - 4 * a * c;
        if((double)D < 0)
        {
            cout<<endl;
            cout<<"Нет действительных корней"<<endl;
        }
        else if((double)D == 0)
        {
            x1 = -b / (2 * a);
            cout<<endl;
            cout<<"Корни одинаковы, так как дискриминант равен 0"<<endl;
            cout<<"Корни: "<<x1<<" "<<x1<<endl;
        }
        else if((double)D > 0)
        {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            cout<<endl;
            cout<<"Уравнение имеет два корня"<<endl;
            cout<<"Корни: "<<x1<<" "<<x2<<endl;
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
