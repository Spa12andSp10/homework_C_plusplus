#include "play.h"
#include <iostream>
#include <ctime>
using namespace std;


void getAllNumbers(int (*result)[LEN_NUM])
{
    int res_index = 0;
    for(int i = 123; i <= 9999; i++)
    {
        int tmp = i;
        int index = LEN_NUM - 1;
        while(tmp > 0)
        {
            result[res_index][index] = tmp % 10;
            tmp /= 10;
            index--;
        }
        res_index++;
    }
}


// Функция для отбора чисел с уникальными цифрами
int OnlyUniqueNumbers(int (*result)[LEN_NUM], int (*uniqueNumbers)[LEN_NUM])
{
    int index = 0;
    for(int i = 0; i < All_NUMBERS; i++)
    {
        bool flag = true;
        bool digits[10] = {false};

        for(int j = 0; j < LEN_NUM; j++)
        {
            int digit = result[i][j];
            if (digits[digit])
            {
                flag = false;
                break;
            }
            digits[digit] = true;
        }

        if (flag)
        {
            for(int j = 0; j < LEN_NUM; j++)
            {
                uniqueNumbers[index][j] = result[i][j];
            }
            index++;
        }
    }
    return index;
}


// Функция для получения рандомного числа из массива uniqueNumbers
void getOneNumber(int (*uniqueNumbers)[LEN_NUM], int *oneNumber)
{
    srand(time(NULL));
    int num;
    do
    {
        num = rand() % MAX_LEN;
    } while(uniqueNumbers[num][0] == -1 && uniqueNumbers[num][1] == -1 &&
            uniqueNumbers[num][2] == -1 && uniqueNumbers[num][3] == -1);
    for(int i = 0; i < LEN_NUM; i++)
    {
        oneNumber[i] = uniqueNumbers[num][i];
    }
}


// Функция для подсчета быков и коров
void BullsAndCows(int *number, int *true_number, int &bull, int &cow)
{
    bull = 0;
    cow = 0;
    for(int i = 0; i < LEN_NUM; i++)
    {
        for(int j = 0; j < LEN_NUM; j++)
        {
            if(number[j] == true_number[i] && i == j)
                bull++;
            else if(number[j] == true_number[i] && i != j)
                cow++;
        }
    }
}


// Функция для удаления неправильных чисел
void deleteBadNumbers(int (*uniqueNumbers)[LEN_NUM], int *oneNumber, int bull, int cow)
{
    for (int i = 0; i < MAX_LEN; ++i)
    {
        int tmpBull = 0, tmpCow = 0;
        BullsAndCows(uniqueNumbers[i], oneNumber, tmpBull, tmpCow);
        if (tmpBull != bull || tmpCow != cow)
        {
            for (int j = 0; j < LEN_NUM; ++j)
            {
                uniqueNumbers[i][j] = -1;
            }
        }
    }
}


// Функция для ввода пользователя
void inputNumber(int *player)
{
    unsigned int num, cnt = 0;
    bool flagUn;
    int check[LEN_NUM] = {-1, -1, -1, -1};
    do
    {
        flagUn = true;
        cout<<"Введите 4-х значное число, в котором нет повторяющихся цифр: ";
        cin>>num;
        for(int i = 0; i < LEN_NUM; i++)
        {
            int ch = num % 10;
            for(int j = 0; j < LEN_NUM; j++)
            {
                if(ch == check[j])
                {
                    flagUn = false;
                    break;
                }
            }
            if(flagUn == false)
                break;
            else
            {
                check[i] = ch;
                player[LEN_NUM - 1 - i] = ch;
                num /= 10;
            }
        }

    }while(flagUn == false);
}
