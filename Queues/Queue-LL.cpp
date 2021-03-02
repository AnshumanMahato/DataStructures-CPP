#include <bits/stdc++.h>

struct NODE
{
    int data;
    NODE *next;
};

class Queue
{
private:
    NODE *front,*rear;
    int len;
    bool underflow()
    {
        return (front == NULL);
    }
public:
    Queue();
    ~Queue();
    void enqueue();
    int dequeue();
    int getFront();
    int getRear();
    int get();
    void show();  
};

Queue::Queue()
{
    front = rear = NULL;
    len = 0;
}

Queue::~Queue()
{
}
