#include <bits/stdc++.h>

struct node
{
    int data;
    node *next;
};

class Stack
{
private:
    node *top;
    int len;
    bool underflow()
    {
        return (top == NULL);
    }
public:
    Stack()
    {      
        top = NULL;
        len = 0;
    }
    void push(int);
    int pop();
    int peek();
    int get(int);
    void show();
};

void Stack::push(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = top;
    top = temp;
    len++;
}

int Stack::peek()
{
    if(underflow())
        return INT32_MIN;
    return top->data;
}

int Stack::pop()
{
    if(underflow())
        return INT32_MIN;
    
    node *temp = top;
    top = top->next;
    int n = temp->data;
    delete temp;
    return n;
}

int Stack::get(int pos)
{
    if(underflow())
        return INT32_MIN;
    node *temp = top;
    for(int i = len-1; i >= 0; i--)
    {
        if(i == pos)
            return temp->data;
        temp = temp->next;
    }

    return INT32_MAX;
}

void Stack::show()
{
    if(underflow())
        std::cout << "Underflow in Stack";
    else
    {
        for(node *itr = top; itr != NULL; itr = itr->next)
        {
            std::cout << itr->data << ' ';
        }
    }

}

int main()
{
    Stack st;
    int n,value,pos;
    do
    {
        std::cout << "\nStack Menu\n"
                  << "\n1.Push Element"
                  << "\n2.Pop Element"
                  << "\n3.Show Stack Elements"
                  << "\n4.Peek Stack"
                  << "\n5.Get Element"
                  << "\n6.Exit"
                  << "\nEnter choice between 1-6";
        std::cin >> n;
        switch (n)
        {
        case 1:
            std::cout << "Enter no.:";
            std::cin >> value;
            st.push(value);
            break;
        case 2:
            value = st.pop();
            if(value == INT32_MIN)
                std::cout << "Underflow in stack.";
            else
                std::cout << "Popped Value:" << value;
            break;
        case 3:
            std::cout << "Stack:";
            st.show();
            break;
        case 4:
            value = st.peek();
            if(value == INT32_MIN)
                std::cout << "Underflow in stack.";
            else
                std::cout << "Top Value:" << value;
            break;
        case 5:
            std::cout << "Enter position value.:";
            std::cin >> pos;
            value = st.get(pos);
            if(value == INT32_MIN)
                std::cout << "Underflow in stack.";
            else if (value == INT32_MAX)
                std::cout << "Position not in range";
            else
                std::cout << "Value at " << pos <<':' << value;
            break;
        case 6:
            std::cout << "Quitting...";
            break;
        default:
            std::cout << "Invalid option";
            break;
        }
    } while (n != 6);
    
    return 0;
}