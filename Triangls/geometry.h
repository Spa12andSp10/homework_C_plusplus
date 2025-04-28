#ifndef _GEOMETRY_H
#define _GEOMETRY_H
#include <iostream>
using namespace std;
struct Point
{
    double x, y;
};
struct Triangle
{
    Point vertexes[3];
    double area;
    double perimeter;

};
double calcDistance(double xa, double ya, double xb, double yb);
double calcAreaBySides(double a, double b, double c);
double calcPerimeterBySides(double a, double b, double c);
double calcTriangleArea(Triangle& tr, int check);
void clearPoint(Point &p);
void clearTriangle(Triangle &tr, int check);

istream &operator>>(istream &in, Point &p);
ostream &operator<<(ostream &out, const Point &p);
ostream &operator<<(ostream &out, const Triangle &tr);
ostream& perimeterOutput(ostream& out, const Triangle& tr);
#endif
