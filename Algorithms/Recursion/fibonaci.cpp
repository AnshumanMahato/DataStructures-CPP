#include<bits/stdc++.h>

int fibonacci(int);

int count = 0;

int main()
{
    int num;
    std::cout<<"Enter no.";
    std::cin>>num;
    for (int i = 0; i <= num ; i++)
    {
        std::cout<<fibonacci(i)<<' ';
    }

    std::cout<<std::endl<<count;
    return 0;
}

int fibonacci(int key)
{
    count++;
    if(key < 2)
        return key;
    else
        return fibonacci(key-1) + fibonacci(key-2);
}