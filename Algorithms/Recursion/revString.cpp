#include<bits/stdc++.h>

std::string reverse(std::string);

int main()
{
    std::string input = "Hello Bot!!!";
    std::cout<<reverse(input);
    return 0;
}

std::string reverse(std::string str)
{
    std::string result = "";
    result.push_back(*str.rbegin());
    str.pop_back();
    if(!str.length())
        return result;
    return result + reverse(str);
}