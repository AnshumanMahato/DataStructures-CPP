#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> squares(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int k = nums.size() - 1;
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                squares[k] = nums[left] * nums[left];
                left++;
            }
            else{
                squares[k] = nums[right] * nums[right];
                right--;
            }
            k--;
        }
        return squares;
    }
};