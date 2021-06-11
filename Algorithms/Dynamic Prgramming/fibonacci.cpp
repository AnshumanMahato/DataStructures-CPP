#include <bits/stdc++.h>

int fibonacci(int);

int main()
{
    int input;
    std::cin>>input;

    std::cout<<fibonacci(input);

    return 0;
}

int fibonacci(int key)
{
    static std::unordered_map<int,int> cache;
    if(cache.find(key) == cache.end())
    {
        if(key < 2)
            cache[key] = key;
        else
            cache[key] = fibonacci(key-1) + fibonacci(key-2);
    }

    return cache[key];
}