#include "data.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

void filePath(char* user_date, char* year, char* path)
{
    char* date_pos = strstr(user_date, ".");
    if (date_pos == NULL)
    {
        cout<<"ERROR: Некорректный формат даты"<<endl;
    }

    strncpy(year, date_pos + 4, 4);
    year[4] = '\0';

    char* year_position = strstr(path, "YYYY");
    if (year_position == NULL)
    {
        cout<<"ERROR: Не найдено 'YYYY' в пути"<<endl;
    }
    memcpy(year_position, year, 4);
}

void newUserData(const char* user_date, string& new_user_data, int len)
{
    int index = len - 1;
    int k = 0;

    for (int i = 0; i < len; i++)
    {
        if (user_date[i] == '.' || user_date[i] == '\0')
        {
            for (int j = i - 1; j >= k; j--)
            {
                if (user_date[j] != '.')
                {
                    new_user_data += user_date[j];
                }
            }
            k = i + 1;
        }
    }

    for (int j = len - 1; j >= k; j--)
    {
        if (user_date[j] != '.')
        {
            new_user_data += user_date[j];
        }
    }
    reverse(new_user_data.begin(), new_user_data.end());
}

streampos find_date(ifstream& file, const string& target_date) {
    string line;
    streampos left = 0, right, mid, last_valid_pos = -1;

    file.seekg(0, ios::end);
    right = file.tellg();
    file.clear();

    while (left < right) {
        mid = left + (right - left) / 2;
        file.seekg(mid, ios::beg);

        if (mid != 0) {
            getline(file, line);
        }

        streampos current_pos = file.tellg();
        if (!getline(file, line)) {
            break;
        }

        string date = line.substr(0, 8);

        if (date == target_date) {
            last_valid_pos = current_pos;
            right = mid;
        }
        else if (date < target_date) {
            left = file.tellg();
        }
        else {
            right = mid;
        }
    }

    return last_valid_pos;
}
