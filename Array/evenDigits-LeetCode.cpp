#include <bits/stdc++.h>

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        
        int count = 0;
        
        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            int dig_count = 0;
            while(*i)
            {
                *i /= 10;
                dig_count++;
            }
            
            if(dig_count%2 == 0)
                count++;
        }
        
        return count ;
        
    }
};