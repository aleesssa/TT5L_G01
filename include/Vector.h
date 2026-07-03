#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cstdlib>

using namespace std;

/*=========================================================
Tempalte: Vector
Author: QAISARAH SHAMSUL AZRAN
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
        capacity *= 2;  //double the array capacity

        T* temp = new T[capacity];  //create a dynamic temporary array

        for(int i = 0; i < length; i++)
            temp[i] = data[i];  //assign all elements from old array to new array

        delete[] data;  //delete old array

        data = temp;    //temp array is the new data array
    }

public:
    Vector()
    {
        capacity = 4;
        length = 0;
        data = new T[capacity]; //when a vector is created, a dynamic array with capacity 4 is created
    }

    ~Vector()
    {
        delete[] data;  //delete the dynamic array from memory
    }

    void push_back(T value)
    {
        if(length == capacity)  //if the length of the elements in the array has reached max capacity, the array resizes
            resize();

        data[length] = value;   //assign the given value to the last index
        length++;   //increase length aka the index
    }

    void pop_back()
    {
        if(length == 0)
        {
            cout << "Vector is empty." << endl; //if the array is empty, give error message
            return;
        }

        length--;   //reduce the length aka the index so that cannot access the last element
    }

    bool empty()
    {
        if(length == 0)
        {
            return true;    //return true if empty
        }
        else
        {
            return false;   //return  false if not empty
        }
    }

    void insert(int index, T value)
    {
        if(length == capacity)  //if the length of the elements in the array has reached max capacity, the array resizes
        {
            resize();
        }

        if(index < 0 || index > length)
        {
            cout<<"Index out of range\n";   //if the index value given is more than the length of the array or less than 0, give error message
            return;
        }

        for(int i = length; i > index; i--)
        {
            data[i] = data[i-1];    //shifting/copying all elements from the desired index location to the right
        }

        data[index] = value;    //assign the value given to the index position
        length++;   //increase length
    }

    T& operator[](int index)
    {
        if(index < 0 || index >= length)
        {
            cout<<"Index out of range\n";   //if the index value given is more than the length of the array or less than 0, give error message
            exit(1);
        }
        return data[index]; //when operator [] is used, it returns the value at the given index
    }

    int size()
    {
        return length;
    }
};

#endif