#include <iostream>
#include "play.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int check[All_NUMBERS][LEN_NUM] = {0};

    int myTry[LEN_NUM];
    int enemy[LEN_NUM];
    int bull = 0, cow = 0, playerBull, playerCow;

    getAllNumbers(check);

    int uniqueNumbers[MAX_LEN][LEN_NUM] = {0};
    int uniqueCount = OnlyUniqueNumbers(check, uniqueNumbers);

    int oneNumber[LEN_NUM];
    getOneNumber(uniqueNumbers, oneNumber);
    //�������� ���� ��� ����
    while(true)
    {
        cout << "=============== ��� ��� ===============" << endl;
        cout << "�������� ����� ����������" << endl;
        inputNumber(myTry);
        BullsAndCows(myTry, oneNumber, bull, cow);
        cout << "����� " << bull << " ����� " << cow << endl;
        if(bull == 4)
        {
            cout<<endl;
            cout << "=============== ��� ��������� ���... ===============" << endl;
            getOneNumber(uniqueNumbers, enemy);
            cout << "� ������, ��� ���� �����: ";
            for(int i = 0; i < LEN_NUM; i++)
            {
                cout << enemy[i];
            }
            cout << endl;
            cout<<"�����: ";
            cin>>playerBull;
            cout<<"�����: ";
            cin>>playerCow;
            if(playerBull == 4)
            {
                cout<<endl;
                cout<<"� ��� �����"<<endl;
                cout<<"������� �� ����!!!"<<endl;
                break;
            }
            else
            {
                cout<<endl;
                cout<<"�� ��������!!!"<<endl;
                break;
            }
        }
        cout<<endl;
        cout << "=============== ��� ��� ===============" << endl;
        getOneNumber(uniqueNumbers, enemy);
        cout << "� ������, ��� ���� �����: ";
        for(int i = 0; i < LEN_NUM; i++)
        {
            cout << enemy[i];
        }
        cout << endl;
        do
        {
            cout<<"�����: ";
            cin>>playerBull;
            cout<<"�����: ";
            cin>>playerCow;
        }while(playerBull > 4 || playerCow > 4 || playerBull < 0 || playerCow < 0);

        if(playerBull == 4)
        {
            cout<<endl;
            cout << "� �������!!!" << endl;
            cout << "��� ����� ";
            for(int i = 0; i < LEN_NUM; i++)
            {
                cout << oneNumber[i];
            }
            cout << endl;
            break;
        }
        else
        {
            deleteBadNumbers(uniqueNumbers, enemy, playerBull, playerCow);
        }
        cout<<endl;
    }
    return 0;
}



