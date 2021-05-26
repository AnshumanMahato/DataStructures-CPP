#include<bits/stdc++.h>

void selectionSort(std::vector<int> &);

int main()
{
    std::vector<int> input;
    input.push_back(7);
    input.push_back(2);
    input.push_back(9);
    input.push_back(6);
    input.push_back(1);
    input.push_back(5);

    selectionSort(input);

    std::vector<int>::iterator itr = input.begin();
    while (itr < input.end())
    {
        std::cout<<*itr<<std::endl;
        itr++;
    }
    
    return 0;
}

void selectionSort(std::vector<int>& data)
{
    for (int i = 0; i < data.size(); i++)
    {
        int pos = i;
        for (int j = i; j < data.size(); j++)
        {
            if(data[j] < data[pos])
                pos = j;
        }
        
        int temp = data[i];
        data[i] = data[pos];
        data[pos] = temp;
    }
    
}