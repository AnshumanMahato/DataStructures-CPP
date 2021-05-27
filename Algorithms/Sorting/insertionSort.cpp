#include<bits/stdc++.h>

void insertionSort(std::vector<int> &);

int main()
{
    std::vector<int> input;
    input.push_back(7);
    input.push_back(2);
    input.push_back(9);
    input.push_back(6);
    input.push_back(1);
    input.push_back(5);

    insertionSort(input);

    std::vector<int>::iterator itr = input.begin();
    while (itr < input.end())
    {
        std::cout<<*itr<<std::endl;
        itr++;
    }
    
    return 0;
}

void insertionSort(std::vector<int>& data)
{
    for (int i = 1; i < data.size(); i++)
    {
        int key = data[i];
        int j = i-1;

        while (j>=0 && data[j] > key)
        {
            data[j+1] = data[j];
            j--;
        }
        
        data[j+1] = key;
    }
    
}