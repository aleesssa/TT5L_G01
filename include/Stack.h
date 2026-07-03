#ifndef STACK_H
#define STACK_H

/*=========================================================
Class: Stack
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/

class Stack
{
private:
    signed char stack[8];
    int top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(signed char value);
    signed char pop();
    signed char peek(); //get top element
    int getTop() const; //get top index
};

#endif
