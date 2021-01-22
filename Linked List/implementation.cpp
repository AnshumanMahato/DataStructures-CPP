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


