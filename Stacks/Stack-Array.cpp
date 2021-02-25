#include <bits/stdc++.h>
#include <vector>

class Stack
{
private:
    std::vector<int> stk;
    int top;
public:
    Stack();
    void push(int);
    int pop();
    int peek();
    void get();
    void show();
};

Stack::Stack()
{      
    top = -1;
}

void Stack::push(int n)
{
    stk.push_back(n);
    top++;
}

int Stack::peek()
{
    if(top < 0)
    {
        std::cout<<"Underflow in stack";
        return INT64_MIN;
    }
    return stk[top];
}

int Stack::pop()
{
    int n = peek();
    stk.pop_back();
    top--;
    return n;
}