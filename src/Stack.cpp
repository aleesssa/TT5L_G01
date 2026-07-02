#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack()
{
    top = -1;
}

bool Stack::isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if(top == 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::push(signed char value)
{
    if(isFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    top++;
    stack[top] = value;
}

signed char Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    signed char value;
    value = stack[top];

    top--;

    return value;
}

signed char Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack is empty\n";
        return 0;
    }

    return stack[top];
}

int Stack::getTop()
{
    return top;
}
