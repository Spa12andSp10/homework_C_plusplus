#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "data.h"
#include "parametrs.h"
using namespace std;

const int USERDATA = 11;
const int YEAR = 5;
const int NEWUSERDATA = 10;

int main()
{
    setlocale(LC_ALL, "Russian");
    double t = 0, t2 = 0, t3 = 0, check1 = 0, check2 = 0, check3 = 0;
    char path[] = ".\\Moon\\moonYYYY.dat";
    char user_date[USERDATA];
    char year[YEAR];
    string new_user_data;
    cout << "Введите дату в формате dd.mm.yyyy: ";
    cin >> user_date;
    filePath(user_date, year, path);
    newUserData(user_date, new_user_data, NEWUSERDATA);
    ifstream in(path);
    if (!in.is_open())
    {
        cout << "ERROR: Не удалось открыть файл" << endl;
        return -1;
    }

    string previousLine, currentLine, nextLine;
    string height1, time1, sd1;
    string height2, time2, d2, w;
    string height3, time3, d3;
    int cnt = 0, cnt2 = 0, cnt3 = 0;

    streampos pos = find_date(in, new_user_data);
    if (pos == -1) {
        cout << "ERROR: Дата не найдена в файле" << endl;
        return -1;
    }

    in.clear();
    in.seekg(pos);
    getline(in, currentLine);


    istringstream iss(currentLine);
    while (iss >> w)
    {
        cnt++;
        if (cnt == 1)
        {
            sd1 = w;
            break;
        }
    }
    cnt = 0;

    if (getline(in, nextLine)) {
        while (true) {
            previousLine = currentLine;
            currentLine = nextLine;
            if (!getline(in, nextLine)) {
                nextLine.clear();
            }

            cnt = 0;
            istringstream issPrev(previousLine);
            string word;
            while (issPrev >> word) {
                cnt++;
                if (cnt == 3) {
                    time1 = word;
                }
                if (cnt == 5) {
                    height1 = word;
                }
            }

            cnt2 = 0;
            istringstream issCurr(currentLine);
            while (issCurr >> word) {
                cnt2++;
                if (cnt2 == 1) {
                    d2 = word;
                }
                if (cnt2 == 3) {
                    time2 = word;
                }
                if (cnt2 == 5) {
                    height2 = word;
                }
            }

            cnt3 = 0;
            istringstream issNext(nextLine);
            while (issNext >> word) {
                cnt3++;
                if (cnt3 == 1) {
                    d3 = word;
                }
                if (cnt3 == 3) {
                    time3 = word;
                }
                if (cnt3 == 5) {
                    height3 = word;
                }
            }
            check1 = moonRice(height1, height2, time1, time2, d2, sd1);
            if (check1 > 0) {
                t = check1;
            }

            check2 = moonSet(height1, height2, time1, time2, d2, sd1);
            if (check2 > 0) {
                t2 = check2;
            }

            check3 = moonCulmination(height1, height2, height3, time1, time2, d2, sd1);
            if (check3 > 0) {
                t3 = check3;
            }

            if (d2.substr(6, 2) != sd1) {
                break;
            }
        }
    }


    cout <<"Восход "<< setfill('0') << setw(2) << (int)t <<":"<<setw(2)<< int(((t - (int)t) * 60))<<":"<<setw(2)<< int((((t - (int)t) * 60) - int(((t - (int)t) * 60))) * 60)<< endl;
    cout <<"Кульминация "<<setfill('0')<<setw(2)<< (int)t3 <<":"<<setw(2)<< int(((t3 - (int)t3) * 60))<<":"<<setw(2)<< int((((t3 - (int)t3) * 60) - int(((t3 - (int)t3) * 60))) * 60)<< endl;
    cout <<"Закат "<<setfill('0')<<setw(2)<< (int)t2 <<":"<<setw(2)<< int(((t2 - (int)t2) * 60))<<":"<<setw(2)<< int((((t2 - (int)t2) * 60) - int(((t2 - (int)t2) * 60))) * 60)<< endl;
    return 0;
}
