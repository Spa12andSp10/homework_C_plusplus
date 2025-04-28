#include "search.h"
#include "geometry.h"

void findAndInsert(Triangle* trArray, int length, const Triangle& triangle, int check)
{
    int pos;
    for(pos = length - 1; pos >= 0; pos--)
    {
        if(check == 1)
        {
            if(triangle.area <= trArray[pos].area)
                break;
        }
        else if(check == 0)
        {
            if(triangle.perimeter <= trArray[pos].perimeter)
                break;
        }
    }
    pos++;
    if(pos == length)
        return;
    for(int m = length - 2; m >= pos; m--)
        trArray[m + 1] = trArray[m];
    trArray[pos] = triangle;
}

void searchLargestTriangles(const Point *pointArray, int numPoints, Triangle *trArray, int maxTrNum, int check)
{
    if (maxTrNum <= 0)
    {
        return;
    }

    for (int i = 0; i < maxTrNum; i++)
    {
        clearTriangle(trArray[i], check);
        if(check == 1)
            trArray[i].area = 0.0;
        else if(check == 0)
            trArray[i].perimeter = 0.0;
    }
    for (int i = 0; i < numPoints; i++)
        {
            for (int j = i + 1; j < numPoints; j++)
                {
                    for (int k = j + 1; k < numPoints; k++)
                        {
                        Triangle triangle;
                        triangle.vertexes[0] = pointArray[i];
                        triangle.vertexes[1] = pointArray[j];
                        triangle.vertexes[2] = pointArray[k];
                        calcTriangleArea(triangle, check);
                        findAndInsert(trArray, maxTrNum, triangle, check);
                        }
                }
        }
}

