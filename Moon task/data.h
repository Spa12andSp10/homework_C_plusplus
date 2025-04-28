#include <string>
using namespace std;
#ifndef _DATA_H
#define _DATA_H
void filePath(char* user_date, char* year, char* path);
void newUserData(const char* user_date, string& new_user_data, int len);
streampos find_date(ifstream& file, const string& target_date);
#endif
