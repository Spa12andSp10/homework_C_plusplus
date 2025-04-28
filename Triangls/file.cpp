#include "file.h"
#include <fstream>
using namespace std;

int countPoints(const char* fileName)
{
    ifstream in(fileName);
    if(!in.is_open())
        return -1;
    double x,y;
    int i;
    for(i = 0; ;i++)
    {
        in>>x>>y;
        if(in.fail())
            break;
    }
    return i;
}
bool readPoints(const char *fileName, Point *pointArray, int *numPoints) {
  ifstream in(fileName);
  if (!in.is_open()) {
    return false;
  }

  int i = 0;
  while (in >> pointArray[i] && i < MAX_POINTS) {
    i++;
  }

  *numPoints = i;

  if (in.fail() && !in.eof()) {
    return false;
  }
  return true;
}

bool writeTriangles(const char *fileName, const Triangle *trArray, int trNum, int check) {
  ofstream out(fileName);
  if (!out.is_open()) {
    return false;
  }
  if (check == 1)
  {
      for (int i = 0; i < trNum; i++)
      {
            out << trArray[i] << '\t' << "#" << i + 1 << endl;
      }
      return true;
  }
  else if (check == 0)
  {
      for (int i = 0; i < trNum; i++)
      {
            perimeterOutput(out, trArray[i]) << '\t' << "#" << i + 1 << endl;
      }
      return true;
  }

}
