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
    len++;
}

int Queue::dequeue()
{
    if(underflow())
        return INT32_MIN;
    NODE *temp = front;
    front = front->next;
    len--;
    int n = temp->data;
    delete temp;
    return n;
}

int Queue::getFront()
{
    if(underflow())
        return INT32_MIN;
    return front->data;
}

int Queue::getRear()
{
    if(underflow())
        return INT32_MIN;
    return rear->data;
}

int Queue::get(int pos)
{
    if(underflow())
        return INT32_MIN;
    NODE *temp = front;
    for(int i = 0; i < len; i++)
    {
        if(i == pos)
            return temp->data;
        temp = temp->next;
    }

    return INT32_MAX;
}

void Queue::show()
{
    if(underflow())
        std::cout << "Queue is Empty.";
    else
    {
        for(NODE *itr = front; itr != NULL; itr = itr->next)
        {
            std::cout << itr->data << ' ';
        }
    }
}  

int main()
{
    Queue q;
    int n,value,pos;
    do
    {
        std::cout << "\nQueue Menu\n"
                  << "\n1.Insert Element"
                  << "\n2.Delete Element"
                  << "\n3.Show Queue Elements"
                  << "\n4.Peek Queue Front"
                  << "\n5.Peek Queue Rear"
                  << "\n6.Get Element"
                  << "\n7.Exit"
                  << "\nEnter choice between 1-7";
        std::cin >> n;
        switch (n)
        {
        case 1:
            std::cout << "Enter no.:";
            std::cin >> value;
            q.enqueue(value);
            break;
        case 2:
            value = q.dequeue();
            if(value == INT32_MIN)
                std::cout << "Underflow in stack.";
            else
                std::cout << "Deleted Value:" << value;
            break;
        case 3:
            std::cout << "Queue:";
            q.show();
            break;
        case 4:
            value = q.getFront();
            if(value == INT32_MIN)
                std::cout << "Queue is Empty";
            else
                std::cout << "Front Value:" << value;
            break;
        case 5:
            value = q.getRear();
            if(value == INT32_MIN)
                std::cout << "Queue is Empty";
            else
                std::cout << "Rear Value:" << value;
            break;
        case 6:
            std::cout << "Enter position value.:";
            std::cin >> pos;
            value = q.get(pos);
            if(value == INT32_MIN)
                std::cout << "Queue is empty.";
            else if (value == INT32_MAX)
                std::cout << "Position not in range";
            else
                std::cout << "Value at " << pos <<':' << value;
            break;
        case 7:
            std::cout << "Quitting...";
            break;
        default:
            std::cout << "Invalid option";
            break;
        }
    } while (n != 6);
    
    return 0;
}
