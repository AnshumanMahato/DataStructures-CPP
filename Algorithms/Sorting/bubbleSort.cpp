#include<bits/stdc++.h>

void bubbleSort(std::vector<int> &);

int main()
{
    std::vector<int> input;
    input.push_back(7);
    input.push_back(2);
    input.push_back(9);
    input.push_back(6);
    input.push_back(1);
    input.push_back(5);

    bubbleSort(input);

    std::vector<int>::iterator itr = input.begin();
    while (itr < input.end())
    {
        std::cout<<*itr<<std::endl;
        itr++;
    }
    
    return 0;
}

void bubbleSort(std::vector<int>& data)
{

    for (int i=0; i < data.size(); i++)
    {
        for(int j=0; j < data.size()-1-i; j++)
        {
            if(data[j] > data[j+1])
            {
                int t = data[j];
                data[j] = data[j+1];
                data[j+1] = t;
            }
        }
    }
    
}