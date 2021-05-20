#include<bits/stdc++.h>

int factorial(int);

int main()
{
    int n;
    std::cout<<"Enter no.";
    std::cin>>n;
    std::cout<<factorial(n);
    return 0;
}

int factorial(int num)
{
    if(num == 1)
        return 1;
    else
        return num * factorial(num-1);
}