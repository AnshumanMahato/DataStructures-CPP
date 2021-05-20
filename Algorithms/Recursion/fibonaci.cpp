#include<bits/stdc++.h>

int fibonacci(int);

int main()
{
    int num;
    std::cout<<"Enter no.";
    std::cin>>num;
    std::cout<<fibonacci(num);
    return 0;
}

int fibonacci(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}