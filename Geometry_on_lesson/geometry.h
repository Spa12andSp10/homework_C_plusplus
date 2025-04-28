#ifndef _GEOMETRY_H
#define _GEOMETRY_H
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template <class T>
struct Point
{
    T x, y;
};


class Error
{

};


class Figure {
public:
    virtual ~Figure() = default;
    virtual void name() const = 0;
    virtual double calc_perimeter() const = 0;
    virtual double calc_area() const = 0;
};


template <class T>
class Circle : public Figure
{
private:
    T radius;
public:
    Circle();
    Circle(T aradius);
    void name() const ;
    double calc_perimeter() const;
    double calc_area() const;
};


template <class T>
class Triangle : public Figure
{
private:
    T side1, side2, side3;
public:
    Triangle();
    Triange(const Point<T>& p1, const Point<T>& p2,const Point<T>& p3);
    Triangle(T aside1, T aside2, T aside3);
    Triangle(T x1, T x2, T x3, T y1, T y2, T y3);
    void name() const;
    double calc_perimeter() const;
    double calc_area() const;
};


template <class T>
class Rectangle : public Figure
{
private:
    T side1, side2;
public:
    Rectangle();
    Rectangle(const Point<T>& p1, const Point<T>& p2);
    Rectangle(T aOx1, T aOy1, T aOx2, T aOy2);
    Rectangle(T aside1, T aside2);
    void name() const;
    double calc_perimeter() const;
    double calc_area() const;
};


template <class T>
class Ellipse : public Figure
{
private:
    T radius1, radius2;
public:
    Ellipse();
    Ellipse(T aradius1, T aradius2);
    void name() const;
    double calc_perimeter() const;
    double calc_area() const;
};


template <class T>
class Poligon : public Figure
{
private:
    vector<T> v1;
    vector<T> v2;
    int head;
public:
    Poligon(ifstream& file);
    void name() const;
    double calc_perimeter() const;
    double calc_area() const;
};

template <class T> Circle<T>::Circle()
{
    radius = 1;
}

template <class T> Circle<T>::Circle(T aradius)
{
    radius = aradius;
}

template <class T> void Circle<T>::name() const {
    cout<<"Круг"<<endl;
}

template <class T> double Circle<T>::calc_perimeter() const {
    return 2 * M_PI * radius;
}

template <class T> double Circle<T>::calc_area() const {
    return M_PI * radius * radius;
}


template <class T> Triangle<T>::Triangle()
{
    side1 = 1;
    side2 = 1;
    side3 = 1;
}

template <class T> Triangle<T>::Triange(const Point<T>& p1, const Point<T>& p2,const Point<T>& p3)
{
    side1 = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    side2 = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));
    side3 = sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
    if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1))
        throw Error();
}

template <class T> Triangle<T>::Triangle(T x1, T y1, T x2, T y2, T x3, T y3)
{
    side1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    side2 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    side3 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1))
        throw Error();
}

template <class T> Triangle<T>::Triangle(T aside1, T aside2, T aside3)
{
    side1 = aside1;
    side2 = aside2;
    side3 = aside3;
    if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1))
        throw Error();
}

template <class T> void Triangle<T>::name() const
{
    cout<<"Треугольник"<<endl;
}

template <class T> double Triangle<T>::calc_perimeter() const
{
    return side1 + side2 + side3;
}

template <class T> double Triangle<T>::calc_area() const
{
    double p = (side1 + side2 + side3) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

template <class T> Rectangle<T>::Rectangle()
{
    side1 = 1;
    side2 = 1;
}

template <class T> Rectangle<T>::Rectangle(T aOx1, T aOy1, T aOx2, T aOy2)
{
    side1 = abs(aOx2 - aOx1);
    side2 = abs(aOy2 - aOy1);
}

template <class T> Rectangle<T>::Rectangle(T aside1, T aside2)
{
    side1 = aside1;
    side2 = aside2;
}

template <class T> Rectangle<T>::Rectangle(const Point<T>& p1, const Point<T>& p2)
{
    side1 = abs(p2.x - p1.x);
    side2 = abs(p2.y - p1.y);
}

template <class T> void Rectangle<T>::name() const
{
    cout<<"Прямоугольник"<<endl;
}

template <class T> double Rectangle<T>::calc_perimeter() const
{
    return (side1 + side2) * 2;
}

template <class T> double Rectangle<T>::calc_area() const
{
    return side1 * side2;
}

template <class T> Ellipse<T>::Ellipse()
{
    radius1 = 1;
    radius2 = 2;
}

template <class T >Ellipse<T>::Ellipse(T aradius1,T aradius2)
{
    radius1 = aradius1;
    radius2 = aradius2;
}

template <class T> void Ellipse<T>::name() const
{
    cout<<"Эллипс"<<endl;
}

template <class T> double Ellipse<T>::calc_area() const
{
    return M_PI * radius1 * radius2;
}

template <class T> double Ellipse<T>::calc_perimeter() const
{
    return 2 * M_PI * sqrt((radius1 * radius1 + radius2 * radius2) / 2);
}

template <class T> Poligon<T>::Poligon(ifstream& file)
{
    if(!file.is_open())
    {
        throw Error();
    }
    int header;
    T s, t;
    file>>header;
    head = header;
    while(file>>s>>t)
    {
        v1.push_back(s);
        v2.push_back(t);
    }
}

template <class T> void Poligon<T>::name() const
{
    cout<<"Многоугольник"<<endl;
}

template <class T>
double Poligon<T>::calc_area() const
{
    double total = 0;
    T res1 = T(), res2 = T();

    for(int i = 0; i < head; i++)
    {
        if(i + 1 > head)
        {
            res1 += (v1[i] * v2[0]);
            res2 += (v1[0] * v2[i]);
        }
        else
        {
            res1 += (v1[i] * v2[i + 1]);
            res2 += (v1[i + 1] * v2[i]);
        }
    }
    total = abs(res1 - res2) / 2.0;
    return total;
}
template <class T> double Poligon<T>::calc_perimeter() const
{
    double total;
    for(int i = 0; i < head; i++)
    {
        if(i + 1 > head)
            total += sqrt((v1[0] - v1[i]) * (v1[0] - v1[i]) + (v2[0] - v2[i]) * (v2[0] - v2[i]));
        total += sqrt((v1[i + 1] - v1[i]) * (v1[i + 1] - v1[i]) + (v2[i + 1] - v2[i]) * (v2[i + 1] - v2[i]));
    }
    return total;
}

#endif
