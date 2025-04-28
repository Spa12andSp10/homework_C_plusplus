#include "file.h"
#include "search.h"
#include <iostream>
#include <locale.h>
using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    if(argc < 3)
    {
        cout<<"Запуск: Triangls.exe inf.txt outf.txt"<<endl;
        return -1;
    }
    const char* inFileName = argv[1];
    const char* outFileName = argv[2];
    int pointNum = countPoints(inFileName);
    if (pointNum < 0)
    {
        cout<<"Входной файл не существует"<<endl;
        return -2;
    }
    else if (pointNum < 4)
    {
        cout<<"Входной файл слишком мал"<<endl;
        return -3;
    }
    Point* pointArray = new Point[pointNum];
    if(!readPoints(inFileName, pointArray, &pointNum))
    {
        cout<<"Неизвестная ошибка при вводе точек "<<endl;
        return -3;
    }
    int maxTrNum, check;
    cout<<"Введите число треугольников, которое вы хотите увидеть: ";
    cin>>maxTrNum;
    cout<<"Введите число (0 - периметр, 1 - площадь): ";
    cin>>check;
    Triangle trArray[maxTrNum];
    searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum, check);
    if(!writeTriangles(outFileName, trArray, maxTrNum, check))
    {
        cout<<"Не удалось записать результат"<<endl;
        return -4;
    }
    cout<<"Программа успешно завершена"<<endl;
    delete[] pointArray;
    return 0;

}
