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
    Stack()
    {      
        top = -1;
    }
    void push(int);
    int pop();
    int peek();
    int get(int);
    void show();
};

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
    if(underflow())
        std::cout << "Underflow in Stack";
    else
    {
        for(int i = top; i >= 0; i--)
        {
            std::cout << stk[i] << ' ';
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