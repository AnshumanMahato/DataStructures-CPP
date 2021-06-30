#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int left = 0,right = nums.size();
        
        while(left < right)
        {
            if(nums[left] == val)
            {
                nums[left] = nums[--right];
            }
            else
                left++;
        }
        
        return left;
    }

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2}; // Input array
    int val = 2; // Value to remove
    vector<int> expectedNums = {0,1,4,0,3}; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

    int k = removeElement(nums, val); // Calls your implementation

    assert(k == expectedNums.size());
    sort(nums.begin(),nums.begin()+k); // Sort the first k elements of nums
    for (int i = 0; i < expectedNums.size(); i++) {
        assert(nums[i] == expectedNums[i]);
    }       
        return 0;
    }
