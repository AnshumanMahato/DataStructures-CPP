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
    void enqueue(int);
    int dequeue();
    int getFront();
    int getRear();
    int get(int);
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

void Queue::enqueue(int n)
{
    NODE *temp = new NODE;
    temp->data = n;
    temp->next = NULL;
    if(underflow)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }

}
int Queue::dequeue()
{
    if(underflow())
        return INT32_MIN;
    NODE *temp = front;
    front = front->next;
    int n = temp->data;
    delete temp;
    return n;
}
int getFront();
int getRear();
int get(int pos);
void show();  
