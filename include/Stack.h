#ifndef STACK_H
#define STACK_H

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
    signed char peek();
    int getTop();
};

#endif
