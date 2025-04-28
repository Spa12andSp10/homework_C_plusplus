#ifndef _PLAY_H
#define _PLAY_H
const int All_NUMBERS = 9877;
const int MAX_LEN = 5040;
const int LEN_NUM = 4;

void getAllNumbers(int (*result)[LEN_NUM]);
int OnlyUniqueNumbers(int (*result)[LEN_NUM], int (*uniqueNumbers)[LEN_NUM]);
void getOneNumber(int (*uniqueNumbers)[LEN_NUM], int *oneNumber);
void BullsAndCows(int *number, int *true_number, int &bull, int &cow);
void deleteBadNumbers(int (*uniqueNumbers)[LEN_NUM], int *oneNumber, int bull, int cow);
void inputNumber(int *player);
#endif
