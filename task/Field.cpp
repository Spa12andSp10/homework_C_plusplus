#include "Field.h"
#include <iostream>
using namespace std;
const int DIR_NUMBER = 4;
const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int WIN_LENGTH = 4;

Field::Field(bool isRedFirst)
{
    clear(isRedFirst);
}

void Field::clear(bool isRedFirst)
{
    isRedTurn = isRedFirst;
    winner = EMPTY;
    for(int i = 0; i < FIELD_WIDTH; i++)
    {
        for(int j = 0; j < FIELD_HEIGHT; j++)
        {
            cells[i][j] = EMPTY;
        }
    }
}

bool Field::makeTurn(int column)
{
    if (winner != EMPTY || column < 1 || column > FIELD_WIDTH)
        return false;
    int i = column - 1;
    for(int j = 0; j < FIELD_HEIGHT; j++)
    {
        if(cells[i][j] == EMPTY)
        {
            cells[i][j] = isRedTurn ? RED : YELLOW;
            checkWinner();
            isRedTurn = !isRedTurn;
            return true;
        }
    }
    return false;
}

void Field::checkWinner()
{

    for(int i = 0; i < FIELD_WIDTH; i++)
    {
        for(int j = 0; j < FIELD_HEIGHT; j++)
        {
            Cell start = cells[i][j];
            if(start == EMPTY)
                continue;
            for(int dir = 0; dir < DIR_NUMBER; dir++)
            {
                int lenght = 0, iline = i, jline = j;
                while(++lenght < WIN_LENGTH)
                {
                    iline += di[dir];
                    jline += dj[dir];
                    if(iline < 0 || iline >= FIELD_WIDTH || jline < 0 ||  jline >= FIELD_HEIGHT)
                        break;
                    if(cells[iline][jline] != start)
                        break;
                }
                if(lenght == WIN_LENGTH)
                {
                    winner = start;
                    return;
                }
            }
        }
    }
}

bool Field::isOver() const
{
    if(winner != EMPTY)
        return true;
    for(int i = 0; i < FIELD_WIDTH; i++)
    {
        for(int j = 0; j < FIELD_HEIGHT; j++)
        {
            if(cells[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

bool Field::isWon(bool red) const
{
    return winner == (red ? RED : YELLOW);
}

Cell Field::getCell(int i, int j) const {
    return cells[i][j];
}

bool Field::isRedTurnNow() const {
    return isRedTurn;
}

void Field::print() const {
    for (int j = FIELD_HEIGHT - 1; j >= 0; j--) {
        for (int i = 0; i < FIELD_WIDTH; i++) {
            switch (cells[i][j]) {
            case EMPTY: cout << "*"; break;
            case RED: cout << "R"; break;
            case YELLOW: cout << "Y"; break;
            }
        }
        cout << endl;
    }
}

void Field::printResult() const {
    switch(winner)
    {
    case(RED):
        cout<<"Красный игрок выиграл!"<<endl;
        break;
    case(YELLOW):
        cout<<"Желтый игрок выиграл!"<<endl;
        break;
    case(EMPTY):
        cout<<"Ничья"<<endl;
        break;
    }
}
