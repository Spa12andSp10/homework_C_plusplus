#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"
using namespace std;

vector<vector<char>> load(ifstream& file);
int vertLine(const vector<vector<char>>& grid, int Ox, int Oy);
int horizLine(const vector<vector<char>>& grid, int Ox, int Oy);
int Func8(vector<vector<char>>& grid, int Ox, int Oy);
int Func4(vector<vector<char>>& grid, int Ox, int Oy);
bool isSquare(vector<vector<char>>& grid, int Ox, int Oy, int res);
bool isCircle(vector<vector<char>>& grid, int Ox, int Oy);
bool isDoodle(vector<vector<char>>& grid, int Ox, int Oy, int res);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout<<"Geometry_on_lesson.exe, input.txt"<<endl;
        return 1;
    }
    const char* name = argv[1];
    ifstream file(name);
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return 1;
    }


    vector<vector<char>> grid = load(file);
    int countSquares = 0, countCircle = 0, countDoodle = 0, countTriangle = 0, result;

    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                result = Func8(grid, i, j);
                if(result == 1)
                    continue;
                if(isSquare(grid, i, j, result))
                    countSquares++;
                else if(isCircle(grid, i, j))
                    countCircle++;
                else if(isDoodle(grid, i, j, result))
                    countDoodle++;
                else
                    countTriangle++;
            }
        }
    }


    ofstream out("out.txt");
    if (!out.is_open()) {
        cerr << "Failed to open file" << endl;
        return 2;
    }
    out << "Rectangle = " << countSquares << '\n';
    out << "Circle = " << countCircle << '\n';
    out << "Triangle = " <<countTriangle << '\n';
    out << "Noise = " << countDoodle << '\n';
    cout<<"The data is uploaded to a file"<<endl;
    file.close();
    out.close();
    return 0;
}

vector<vector<char>> load(ifstream& file)
{
    vector<vector<char>> grid;
    string line;

    while(getline(file, line))
    {
        grid.emplace_back(line.begin(), line.end());
    }

    return grid;
}

int vertLine(const vector<vector<char>>& grid, int Ox, int Oy)
{
    int cnt = 1;

    while(grid[Ox + 1][Oy] == '2')
    {
        cnt++;
        Ox++;
    }

    return cnt;
}

int horizLine(const vector<vector<char>>& grid, int Ox, int Oy)
{
    int cnt = 1;

    while(grid[Ox][Oy + 1] == '2')
    {
        cnt++;
        Oy++;
    }

    return cnt;
}

int Func8(vector<vector<char>>& grid, int Ox, int Oy)
{
    if(grid[Ox][Oy] != '1')
        return 0;

    grid[Ox][Oy] = '2';
    return 1 + Func8(grid, Ox - 1, Oy) + Func8(grid, Ox, Oy - 1)
             + Func8(grid, Ox + 1, Oy) + Func8(grid, Ox, Oy + 1)
             + Func8(grid, Ox - 1, Oy - 1) + Func8(grid, Ox + 1, Oy - 1)
             + Func8(grid, Ox + 1, Oy + 1) + Func8(grid, Ox - 1, Oy + 1);
}

int Func4(vector<vector<char>>& grid, int Ox, int Oy)
{
    if(grid[Ox][Oy] != '2')
        return 0;

    grid[Ox][Oy] = '3';
    return 1 + Func4(grid, Ox - 1, Oy) + Func4(grid, Ox, Oy - 1)
             + Func4(grid, Ox + 1, Oy) + Func4(grid, Ox, Oy + 1);
}

bool isSquare(vector<vector<char>>& grid, int Ox, int Oy, int res)
{
    int vert, horiz;
    vert = vertLine(grid, Ox, Oy);
    horiz = horizLine(grid, Ox, Oy);
    Figure* fig = new Rectangle<int>(vert, horiz);
    if(fig->calc_area() == res)
        return true;
    else
        return false;
}

bool isCircle(vector<vector<char>>& grid, int Ox, int Oy)
{
    int vert = vertLine(grid, Ox, Oy);
    if (vert <= 0) return false;
    int res = vert % 2;
    if (res != 1)
        return false;

    int vert2 = (vert - 1) / 2;
    int newOx = Ox + vert2;
    if (newOx >= grid.size() && grid[newOx][Oy] == '0') {
        return false;
    }
    if(grid[newOx][Oy + 1] == '0')
        return false;

    int horiz = horizLine(grid, newOx, Oy + 1);

    if(vert2 == horiz)
        return true;
    else
        return false;
}

bool isDoodle(vector<vector<char>>& grid, int Ox, int Oy, int res)
{
    int res2 = Func4(grid, Ox, Oy);
    if(abs(res - res2) == 0 || abs(res - res2) == 1 || abs(res - res2) == 2)
        return false;
    else
        return true;
}
