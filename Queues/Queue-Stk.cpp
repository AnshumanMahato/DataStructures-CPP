#include <bits/stdc++.h>
#include "../Stacks/Stack-LL.cpp"

class Queue
{
private:
    Stack qu_rev,qu_fnt;
    int len;
    bool underflow()
    {
        return (qu_rev.peek() == INT32_MIN && qu_fnt.peek() == INT32_MIN);
    }
public:
    Queue();
    void enqueue(int);
    int dequeue();
    int peek(); 
};

Queue::Queue()
{
    len = 0;
}

void Queue::enqueue(int n)
{
    qu_rev.push(n);
    len++;
}

int Queue::dequeue()
{
    if (underflow())
        return INT32_MIN;
    
    if(qu_fnt.peek()==INT32_MIN)
    {
        while (qu_rev.peek() != INT32_MIN)
        {
            qu_fnt.push(qu_rev.pop());
        }
    }
    len--;

    return qu_fnt.pop();
}

int Queue::peek()
{
    if (underflow())
        return INT32_MIN;
    
    if(qu_fnt.peek()==INT32_MIN)
    {
        while (qu_rev.peek() != INT32_MIN)
        {
            qu_fnt.push(qu_rev.pop());
        }
    }

    return qu_fnt.peek();
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
                  << "\n3.Peek Queue Front"
                  << "\n4.Exit"
                  << "\nEnter choice between 1-4";
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
                std::cout << "Queue is empty.";
            else
                std::cout << "Deleted Value:" << value;
            break;
        case 3:
            value = q.peek();
            if(value == INT32_MIN)
                std::cout << "Queue is Empty";
            else
                std::cout << "Front Value:" << value;
            break;
        case 4:
            std::cout << "Quitting...";
            break;
        default:
            std::cout << "Invalid option";
            break;
        }
    } while (n != 4);
    
    return 0;
}
