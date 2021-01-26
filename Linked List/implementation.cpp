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
    void insert(int,int);
    int remove(int);
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
    len++;
}

void linked_list::prepend(int val)
{
    NODE *temp;
    temp = new NODE;
    temp->value = val;
    temp->next = head;
    head = temp;
    len++;
}

void linked_list::insert(int pos,int val) // positioning is just like arrays, i.e, starts from 0;
{
    if(pos == 0)
        prepend(val);
    else if (pos >= len)
        appened(val);
    else
    {
        NODE *temp, *itr;
        temp = new NODE;
        temp->value = val;
        itr = head;
        for(int i = 0; i < pos-1; i++)
        {
            itr = itr->next;
        }   

        temp->next = itr->next;
        itr->next = temp;
    }
}

int linked_list::remove(int pos)
{
    if(pos < 0 || pos >= len)
    {
        std::cout << "\nInvalid Index. Should be between 0 and " << len-1;
        return 0;
    }

    NODE *temp,*itr;
    int removed_val;
    itr = head;
    for(int i = 0; i < pos-1; i++)
    {
        itr = itr->next;
    }
    temp = itr->next;
    removed_val = temp->value;
    itr->next = temp->next;
    delete(temp);
    return removed_val;   
}

void linked_list::show()
{
    NODE *temp;
    temp = head;
    std::cout << std::endl;
    while (temp != NULL)
    {
        std::cout<< temp->value <<',';
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
    list.insert(3,7);
    list.show();
    list.remove(3);
    list.remove(-1);
    list.remove(100);
    list.show();
    return 0;
}

