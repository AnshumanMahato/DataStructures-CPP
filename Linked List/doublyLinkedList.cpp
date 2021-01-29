#include <bits/stdc++.h>

struct NODE
{
    int value;
    NODE *next, *prev;
};

class linked_list
{
private:
    NODE *head,*tail;
    int len;
public:
    linked_list(int);
    ~linked_list();
    NODE* get_node(int);
    void appened(int);
    void prepend(int);
    void insert(int,int);
    int remove(int);
    void show();

    int get_len()
    {
        return len;
    }
};

linked_list::linked_list(int val)
{
    head = new NODE;
    head->value = val;
    head->next = NULL;
    head->prev = NULL;
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

NODE* linked_list:: get_node(int index)
{
    NODE *itr;
    if(index < 0 || index >= len)
        itr = NULL;

    else if(index < len/2)
    {
        itr = head;
        for(int i = 0; i < index; i++)
        {
            itr = itr->next;
        }   
    }

    else
    {
        itr = tail;
        for (int i = len-1; i > index; i--)
        {
            itr = itr->prev;
        }    
    }
    
    return itr;
}

void linked_list::appened(int val)
{
    NODE *temp;
    temp = new NODE;
    temp->value = val;
    temp->next = NULL;
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
    len++;
}

void linked_list::prepend(int val)
{
    NODE *temp;
    temp = new NODE;
    temp->value = val;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    len++;
}

void linked_list::insert(int index,int val) // positioning is just like arrays, i.e, starts from 0;
{
    if(index <= 0)
        prepend(val);
    else if (index >= len)
        appened(val);
    else
    {
        NODE *temp, *itr;
        temp = new NODE;
        temp->value = val;
        itr = get_node(index);
        temp->next = itr;
        temp->prev = itr->prev;
        itr->prev->next = temp;
        itr->prev = temp;
        len++;
    }
}

int linked_list::remove(int index)
{
    if(index < 0 || index >= len)
    {
        std::cout << "\nInvalid Index. Should be between 0 and " << len-1;
        return 0;
    }

    NODE *temp;
    int removed_val;

    if(index == 0)
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
    }

    else if(index == len-1)
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
    }

    else
    {
        temp = get_node(index);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    removed_val = temp->value;
    delete(temp);
    len--;
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
    list.insert(0,17);
    list.insert(11,33);
    list.show();
    list.remove(3);
    list.remove(-1);
    list.remove(100);
    list.show();
    list.remove(0);
    list.remove(list.get_len()-1);
    list.show();
    return 0;
}
