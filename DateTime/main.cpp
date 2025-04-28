#include <iostream>
#include "datetime.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Date userDate, anUserDate;
    int t, i;
    cout<<"Введите дату в формате (ДД ММ ГГГГ): ";
    cin>>userDate;
    cout<<"Введите другую дату, большую или равную предыдущей в формате (ДД ММ ГГГГ): ";
    cin>>anUserDate;
    cout<<"Введите число количество дней ";
    cin>>t;
    Date res = userDate + t;
    cout<<"Через "<<t<<" дней будет это число "<<res<<endl;
    res = userDate - t;
    cout<<"Было "<<res<<" число "<<t<<" назад"<<endl;\
    i = userDate.DifferenceInDates(userDate, anUserDate);
    if(i != -1)
        cout<<"Количество дней до "<<anUserDate<<" равно "<<i<<endl;
    else
        cout<<"Дата "<<anUserDate<<" меньше чем дата "<<userDate<<endl;
    return 0;
}
