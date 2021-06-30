#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(int i = 0;i<k;i++)
        {
            if(nums[i] == val)
            {
                for(int j = i; j < k-1;j++) 
                {
                    nums[j] = nums[j+1];
                    
                }
                k--;
                i--;
            }
        }
        
        return k;
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
