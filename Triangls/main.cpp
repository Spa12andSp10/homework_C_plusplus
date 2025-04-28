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
        cout<<"������: Triangls.exe inf.txt outf.txt"<<endl;
        return -1;
    }
    const char* inFileName = argv[1];
    const char* outFileName = argv[2];
    int pointNum = countPoints(inFileName);
    if (pointNum < 0)
    {
        cout<<"������� ���� �� ����������"<<endl;
        return -2;
    }
    else if (pointNum < 4)
    {
        cout<<"������� ���� ������� ���"<<endl;
        return -3;
    }
    Point* pointArray = new Point[pointNum];
    if(!readPoints(inFileName, pointArray, &pointNum))
    {
        cout<<"����������� ������ ��� ����� ����� "<<endl;
        return -3;
    }
    int maxTrNum, check;
    cout<<"������� ����� �������������, ������� �� ������ �������: ";
    cin>>maxTrNum;
    cout<<"������� ����� (0 - ��������, 1 - �������): ";
    cin>>check;
    Triangle trArray[maxTrNum];
    searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum, check);
    if(!writeTriangles(outFileName, trArray, maxTrNum, check))
    {
        cout<<"�� ������� �������� ���������"<<endl;
        return -4;
    }
    cout<<"��������� ������� ���������"<<endl;
    delete[] pointArray;
    return 0;

}
