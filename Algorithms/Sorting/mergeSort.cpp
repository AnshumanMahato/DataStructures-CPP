#include<bits/stdc++.h>

void mergeSort(std::vector<int>&);
std::vector<int> merge(std::vector<int>&,std::vector<int>&);

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

void mergeSort(std::vector<int>& data)
{   
    if(data.size() == 1)
        return;
    int mid = data.size()/2;

    std::vector<int> left(data.begin(),data.begin()+mid);
    std::vector<int> right(data.begin()+mid,data.end());
    mergeSort(left);
    mergeSort(right);
    data = merge(left,right);
}

std::vector<int> merge(std::vector<int>& arr1,std::vector<int>& arr2)
{
    int i = 0, j = 0;
    std::vector<int> mergedArr;

    while (i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
            mergedArr.push_back(arr1[i++]);
        else
            mergedArr.push_back(arr2[j++]);
    }

    while (i < arr1.size())
    {
        mergedArr.push_back(arr1[i++]);
    }

    while (j < arr2.size())
    {
        mergedArr.push_back(arr2[j++]);
    }

    return mergedArr;
    
}

