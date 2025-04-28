#include <iostream>
#include <ctime>
using namespace std;


typedef int (*func_ptr)(int**, int);
int firstNum(int **cloud, int num);
int secondNum(int **cloud, int num);
int thirdNum(int **cloud, int num);
int fourthNum(int **cloud, int num);
int fifthNum(int **cloud, int num);
int sixthNum(int **cloud, int num);
void decimalToBinary(int num, int *binary);

int main()
{
    setlocale(LC_ALL, "Russian");
    const int BINARY_SIZE = 6;
    const int NUM = 8;
    int OX, OY;

    do
    {
        cout<<"Троль вводит координату OX (0 <= OX <= 7): ";
        cin>>OX;
    }while(OX < 0 || OX > 7);

    do
    {
        cout<<"Троль вводит координату OY (0 <= OY <= 7): ";
        cin>>OY;
    }while(OY < 0 || OY > 7);


    srand(time(NULL));

    int* my_arr = new int[BINARY_SIZE];
    int** cloud = new int*[NUM];
    for (int i = 0; i < NUM; i++)
    {
        cloud[i] = new int[NUM];
    }

    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            cloud[i][j] = rand() % 2;
        }
    }

    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            cout << cloud[i][j] << '\t';
        }
        cout << endl;
    }

    cout<<endl<<endl;

    int*** check = new int**[NUM];
    for (int i = 0; i < NUM; i++)
    {
        check[i] = new int*[NUM];
        for (int j = 0; j < NUM; j++)
        {
            check[i][j] = new int[BINARY_SIZE];
        }
    }

    int cnt = 0;
    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            decimalToBinary(cnt, check[i][j]);
            cnt++;
        }
    }

    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            for (int k = 0; k < BINARY_SIZE; k++)
            {
                cout << check[i][j][k];
            }
            cout << "\t";
        }
        cout << endl;
    }


    cout<<endl<<endl;
    cout<<"Троль указал на число ";
    for(int i = 0; i < BINARY_SIZE; i++)
    {
        cout<<check[OX][OY][i];
    }
    cout<<endl;

    func_ptr functions[6] = { firstNum, secondNum, thirdNum, fourthNum, fifthNum, sixthNum };
    for(int i = 0; i < BINARY_SIZE; i++)
    {
        int res = check[OX][OY][i] ^ functions[BINARY_SIZE - i - 1](cloud, NUM);
        my_arr[i] = res;
    }

    cout<<endl<<endl;

    cout<<"Первый программист перевернул монету ";
    for(int i = 0; i < BINARY_SIZE; i++)
    {
        cout<<my_arr[i];
    }
    cout<<endl;

    int cn = 0;
    int new_j, new_i;
    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            for (int k = 0; k < BINARY_SIZE; k++)
            {
                if(check[i][j][k] == my_arr[k])
                {
                    cn++;
                }
                else
                {
                    cn = 0;
                    break;
                }
            }
            if(cn == 6)
            {
                new_j = j;
                break;
            }
        }
        if(cn == 6)
        {
            new_i = i;
            break;
        }
    }

    if(cloud[new_i][new_j] == 1)
        cloud[new_i][new_j] = 0;
    else if(cloud[new_i][new_j] == 0)
        cloud[new_i][new_j] = 1;


    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            cout<<cloud[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    cout<<"Второй программист выбрал число ";
    for(int i = BINARY_SIZE - 1; i >= 0; i--)
    {
        cout<<functions[i](cloud, NUM);
    }
    cout<<endl;


    for (int i = 0; i < NUM; ++i) {
        for (int j = 0; j < NUM; ++j) {
            delete[] check[i][j];
        }
        delete[] check[i];
    }
    delete[] check;

    for (int i = 0; i < NUM; ++i) {
        delete[] cloud[i];
    }
    delete[] cloud;
    delete[] my_arr;

    return 0;
}

int firstNum(int **cloud, int num)
{
    int total = 0;
    for(int i = 1; i < num; i += 2)
    {
        for(int j = 0; j < num; j++)
        {
            if(cloud[j][i] == 1)
                total++;
        }
    }
    return total % 2;
}

int secondNum(int **cloud, int num)
{
    int total = 0, check = 1;
    for(int i = 2; i < num;)
    {
        for(int j = 0; j < num; j++)
        {
            if(cloud[j][i] == 1)
                total++;
        }
        if(check != 2)
        {
            i += 1;
            check++;
        }
        else
        {
            i += 3;
            check = 1;
        }
    }
    return total % 2;
}

int thirdNum(int **cloud, int num)
{
    int total = 0;
    for(int i = 0; i < num; i++)
    {
        for(int j = 4; j < num; j++)
        {
            if(cloud[i][j] == 1)
                total++;
        }
    }
    return total % 2;
}

int fourthNum(int **cloud, int num)
{
        int total = 0;
    for(int i = 1; i < num; i += 2)
    {
        for(int j = 0; j < num; j++)
        {
            if(cloud[i][j] == 1)
                total++;
        }
    }
    return total % 2;
}

int fifthNum(int **cloud, int num)
{
    int total = 0, check = 1;
    for(int i = 2; i < num;)
    {
        for(int j = 0; j < num; j++)
        {
            if(cloud[i][j] == 1)
                total++;
        }
        if(check != 2)
        {
            i += 1;
            check++;
        }
        else
        {
            i += 3;
            check = 1;
        }
    }
    return total % 2;
}

int sixthNum(int **cloud, int num)
{
    int total = 0;
    for(int i = 0; i < num; i++)
    {
        for(int j = 4; j < num; j++)
        {
            if(cloud[j][i] == 1)
                total++;
        }
    }
    return total % 2;
}

void decimalToBinary(int num, int *binary) {
    for (int i = 5; i >= 0 && num > 0; i--) {
        binary[i] = num % 2;
        num /= 2;
    }
}






