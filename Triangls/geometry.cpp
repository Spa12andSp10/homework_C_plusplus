#include "geometry.h"
#include <cmath>
using namespace std;

double calcDistance(const Point& pa, const Point& pb)
{
    return sqrt((pb.x - pa.x) * (pb.x - pa.x) + (pb.y - pa.y) * (pb.y - pa.y));
}

double calcTriangleArea(Triangle& tr, int check)
{
    Point* v = tr.vertexes;
    double a = calcDistance(v[0], v[1]);
    double b = calcDistance(v[1], v[2]);
    double c = calcDistance(v[2], v[0]);
    if(check == 0)
        return tr.perimeter = calcPerimeterBySides(a, b, c);
    else if(check == 1)
        return tr.area = calcAreaBySides(a, b, c);
}

double calcAreaBySides(double a, double b, double c)
{
    double p2 = (a+b+c)/2.0;
    if(p2 <= 0.0 || p2 <= a || p2 <= b || p2 <= c)
        return 0.0;
    return sqrt(p2 * (p2 - a) * (p2 - b) * (p2 - c));
}

double calcPerimeterBySides(double a, double b, double c)
{
    double p = a + b + c;
    if(p <= 0.0 || p <= a || p <= b || p <= c)
        return 0.0;
    return p;
}

void clearPoint(Point &p)
{
    p.x = p.y = 0.0;
}

void clearTriangle(Triangle &tr, int check)
{
    if(check == 0)
        tr.perimeter = 0.0;
    else if(check == 1)
        tr.area = 0.0;
}

istream &operator>>(istream &in, Point &p) {
  in >> p.x >> p.y;
  return in;
}

ostream &operator<<(ostream &out, const Point &p) {
  out << "(" << p.x << " " << p.y << ")";
  return out;
}

ostream &operator<<(ostream &out, const Triangle &tr) {
        out << "A=" << tr.vertexes[0] << " B=" << tr.vertexes[1] << " C=" << tr.vertexes[2] << " area=" << tr.area;
  return out;
}

ostream& perimeterOutput(ostream& out, const Triangle& tr)
{
    out << "A=" << tr.vertexes[0]<< " B=" << tr.vertexes[1]<< " C=" << tr.vertexes[2]<< " perimeter=" << tr.perimeter;
    return out;
}
