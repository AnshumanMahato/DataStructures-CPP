#include <bits/stdc++.h>
#include <vector>

class Stack
{
private:
    std::vector<int> stk;
    int top;
    bool underflow()
    {
        return (top < 0);
    }
public:
    Stack();
    void push(int);
    int pop();
    int peek();
    int get(int);
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
    if(underflow())
        return INT32_MIN;
    return stk[top];
}

int Stack::pop()
{
    if(underflow())
        return INT32_MIN;
    int n = stk[top--];
    stk.pop_back();
    return n;
}

int Stack::get(int pos)
{
    if(underflow())
        return INT32_MIN;
    if(pos < 0 || pos > top)
        return INT32_MIN;
}