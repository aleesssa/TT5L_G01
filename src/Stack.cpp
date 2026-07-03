#include <iostream>
#include "Stack.h"
using namespace std;

/*=========================================================
Implementation: Stack
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/

Stack::Stack()
{
    top = -1;
}

bool Stack::isEmpty()
{
    if(top == -1)
    {
        return true;    //return true if empty
    }
    else
    {
        return false;   //return false if not empty
    }
}

bool Stack::isFull()
{
    if(top == 7)
    {
        return true;    //return true if full aka there are 8 elements in the stack
    }
    else
    {
        return false;   //return false if not full
    }
}

void Stack::push(signed char value)
{
    if(isFull())
    {
        cout << "Stack Overflow" << endl;   //give error message if stack is full
        return;
    }

    top++;  //increase top index value
    stack[top] = value; //assign given value to top of stack
}

signed char Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack Underflow" << endl;  //give error message if stack is empty
        return 0;
    }

    signed char value;
    value = stack[top]; //assign the top most element of the stack to variable value

    top--;  //decrease the top index to 'remove' the element from stack

    return value;   //return the value variable which is the top most element that was 'removed'
}

signed char Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack is empty\n"; //give error message if stack is empty
        return 0;
    }

    return stack[top];  //return the top most element
}

int Stack::getTop() const
{
    return top; //return the top element's index
}