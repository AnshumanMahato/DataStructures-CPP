#include <bits/stdc++.h>
#include "../Stacks/Stack-LL.cpp"

class Queue
{
private:
    Stack qu;
    int len;
    bool underflow()
    {
        return (qu.peek() == INT32_MIN);
    }
public:
    Queue();
    ~Queue();
    void enqueue(int);
    int dequeue();
    int getFront();
    int getRear();
    int get(int);
    void show();  
};