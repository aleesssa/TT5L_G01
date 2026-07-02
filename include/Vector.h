#ifndef VECTOR_H
#define VECTOR_H

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

        T* temp = new T[length-1];

        for(int i = 0; i < length-1; i++)
            temp[i] = data[i];

        delete[] data;

        data = temp;
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
        
        for(int i = length; i > index; i--)
        {
            data[i] = data[i-1];
        }

        data[index] = value;
        length++;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    int size()
    {
        return length;
    }
};

#endif
