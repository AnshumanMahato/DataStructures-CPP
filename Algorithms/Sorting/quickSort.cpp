#include<bits/stdc++.h>

void quickSort(std::vector<int>&,std::vector<int>::iterator,std::vector<int>::iterator);
std::vector<int>::iterator partition(std::vector<int>&,std::vector<int>::iterator,std::vector<int>::iterator);

int main()
{
    std::vector<int> input;
    input.push_back(7);
    input.push_back(2);
    input.push_back(9);
    input.push_back(6);
    input.push_back(1);
    input.push_back(5);

    quickSort(input);

    std::vector<int>::iterator itr = input.begin();
    while (itr < input.end())
    {
        std::cout<<*itr<<std::endl;
        itr++;
    }
    
    return 0;
}

void quickSort(std::vector<int>& data)
{   
  
}

