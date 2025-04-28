#include "geometry.h"
#ifndef _SEARCH_H
#define _SEARCH_H
void searchLargestTriangles(const Point* pointArray, int pointNum, Triangle* trArray, int maxTrNum, int check);
void findAndInsert(Triangle* trArray, int length, const Triangle& triangle, int check);
#endif
