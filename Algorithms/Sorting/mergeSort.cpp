#include<bits/stdc++.h>

std::vector<int> mergeSort(std::vector<int>);
std::vector<int> merge(std::vector<int>,std::vector<int>);

int main()
{
    std::vector<int> input;
    input.push_back(7);
    input.push_back(2);
    input.push_back(9);
    input.push_back(6);
    input.push_back(1);
    input.push_back(5);

    mergeSort(input);

    std::vector<int>::iterator itr = input.begin();
    while (itr < input.end())
    {
        std::cout<<*itr<<std::endl;
        itr++;
    }
    
    return 0;
}

std::vector<int> mergeSort(std::vector<int> data)
{   
    if(data.size() == 1)
        return data;
    int mid = data.size()/2;

    std::vector<int> left(data.begin(),data.begin()+mid);
    std::vector<int> right(data.begin()+mid+1,data.end());

    return merge(mergeSort(left),mergeSort(right));
}