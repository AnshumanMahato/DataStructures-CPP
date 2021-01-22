#include <bits/stdc++.h>

struct NODE
{
    int value;
    NODE *next;
};

class linked_list
{
private:
    NODE *head,*tail;
    int len;
public:
    linked_list(int);
    ~linked_list();
    void appened(int);
    void prepend(int);
    void show();
};

linked_list::linked_list(int val)
{
    head = new NODE;
    head->value = val;
    head->next = NULL;
    tail = head;
    len = 1;
}

linked_list::~linked_list()
{
    NODE *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete(temp);
    }
    delete(tail);
    len = 0;
}

void linked_list::appened(int val)
{
    NODE *temp;
    temp = new NODE;
    temp->value = val;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void linked_list::prepend(int val)
{
    NODE *temp;
    temp = new NODE;
    temp->value = val;
    temp->next = head;
    head = temp;
}

void linked_list::show()
{
    NODE *temp;
    temp = head;
    while (temp != NULL)
    {
        std::cout<< temp->value <<std::endl;
        temp = temp->next;
    }
    
}

int main()
{
    linked_list list(1);
    list.show();
    list.appened(2);
    list.appened(3);
    list.show();
    list.prepend(0);
    list.prepend(-1);
    list.show();
    return 0;
}

