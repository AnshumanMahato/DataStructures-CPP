#include<bits/stdc++.h>

void quickSort(std::vector<int>&);
std::vector<int> merge(std::vector<int>&,int,std::vector<int>&);

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
    if(data.size() < 2)
        return;
    std::vector<int>::iterator pivot = data.end()-1;
    std::vector<int>::iterator itr = data.begin();
    while(itr != pivot)
    {
        if(*itr > *pivot)
        {
            int temp = *(pivot-1);
            *(pivot-1) = *(pivot);
            if(pivot-1 == itr)
                *(pivot) = temp;
            else
            {
                *(pivot) = *(itr);
                *itr = temp;
            }
            
            pivot--; 
        }
        else
            itr++;
    }

    std::vector<int> left(data.begin(),itr);
    std::vector<int> right(itr+1,data.end());

    quickSort(left);
    quickSort(right);

    std::vector<int> res(left.begin(),left.end());
    res.push_back((*pivot));
    res.insert(res.end(),right.begin(),right.end());

    data = res;
}

