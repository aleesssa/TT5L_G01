#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cstdlib>

using namespace std;

/*=========================================================
Tempalte: Vector
Author: QAISARAH
=========================================================*/

template<class T>
class Vector
{
private:

    T* data;
    int length;
    int capacity;

    void resize()
    {
        capacity *= 2;

        T* temp = new T[capacity];

        for(int i = 0; i < length; i++)
            temp[i] = data[i];

        delete[] data;

        data = temp;
    }

public:

    Vector()
    {
        capacity = 4;
        length = 0;
        data = new T[capacity];
    }

    ~Vector()
    {
        delete[] data;
    }

    void push_back(T value)
    {
        if(length == capacity)
            resize();

        data[length] = value;
        length++;
    }

    void pop_back()
    {
        if(length == 0)
        {
            cout << "Vector is empty." << endl;
            return;
        }

        length--;
    }

    bool empty()
    {
        if(length == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int index, T value)
    {
        if(length == capacity)
        {
            resize();
        }

        if(index < 0 || index > length)
        {
            cout<<"Index out of range\n";
            return;
        }

        for(int i = length; i > index; i--)
        {
            data[i] = data[i-1];
        }

        data[index] = value;
        length++;
    }

    T& operator[](int index)
    {
        if(index < 0 || index >= length)
        {
            cout<<"Index out of range\n";
            exit(1);
        }
        return data[index];
    }

    int size()
    {
        return length;
    }
};

#endif
