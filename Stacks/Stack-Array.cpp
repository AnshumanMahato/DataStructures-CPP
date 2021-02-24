#include <bits/stdc++.h>
#include <vector>

class Stack
{
private:
    std::vector<int> stk;
    int top;
public:
    Stack();
    ~Stack();
    void push(int);
    int pop();
    int peek();
    void traverse();
    void show();
};

Stack::Stack(/* args */)
{
}

Stack::~Stack()
{
}
