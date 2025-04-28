#include <iostream>
#include <fstream>
#ifndef _ARRAY_H
#define _ARRAY_H
using namespace std;

const int DEFAULT_CAPACITY = 10;
class ArrayException{};
class Array
{
    int* ptr;
    int size, capacity;
    void increaseCapacity(int newCapacity);
public:
    explicit Array(int startCapacity = DEFAULT_CAPACITY);
    ~Array();
    Array(const Array& arr);
    Array& operator =(const Array& arr);
    int& operator [](int index);
    void insert(int elem, int index);
    void insert(Array& sArr, int index);
    void insert(int elem);
    void remove(int index);
    int getSize() const;
    friend ostream& operator <<(ostream& out, const Array& arr);
};
#endif
