#include <bits/stdc++.h>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int max = 0;
        int cur_cons = 0;
        for(auto i = nums.begin(); i != nums.end(); ++i){
            if(*i){ // 1
                cur_cons++;
            }
            else{ // 0
                if(cur_cons > max)
                    max = cur_cons;
                cur_cons = 0;
            }
        }
        if(cur_cons > max)
            max = cur_cons;
        return max;
    }
};