#include <bits/stdc++.h>

int fibonacci(int);

int count=0;

int main()
{
    int input;
    std::cin>>input;

    for (int i = 0; i <= input ; i++)
    {
        std::cout<<fibonacci(i)<<' ';
    }

    std::cout<<std::endl<<count;
    return 0;
}

int fibonacci(int key)
{
    static std::unordered_map<int,int> cache;
    if(cache.find(key) == cache.end())
    {
        count++;
        if(key < 2)
            cache[key] = key;
        else
            cache[key] = fibonacci(key-1) + fibonacci(key-2);
    }

    return cache[key];
}