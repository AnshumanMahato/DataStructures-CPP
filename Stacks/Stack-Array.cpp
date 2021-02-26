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
        return INT32_MAX;
    /*
    This is the process how stack elements should be accessed. This opeartion is O(n) as we need to move through 
    all the elements to find the correct position.

    for(int i = top; i >= 0; i--)
    {
        if(i == pos)
            return stk[i];
    }

    But as this stack is implemented over an array ,so stk[pos] can be used and this will make the function 
    O(1) instead of O(n).
    */
    return stk[pos];
}

void Stack::show()
{
    std::cout << std::endl;
    for(int i = top; i >= 0; i--)
    {
        std::cout << stk[i] << ' ';
    }

}