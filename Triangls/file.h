#include "geometry.h"
#ifndef _FILE_H
#define _FILE_H
#define MAX_POINTS 1000
int countPoints(const char *fileName);
bool readPoints(const char *fileName, Point *pointArray, int *numPoints);
bool writeTriangles(const char *fileName, const Triangle *trArray, int trNum, int check);
#endif
