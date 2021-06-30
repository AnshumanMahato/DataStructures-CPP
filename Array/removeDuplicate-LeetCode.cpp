#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
        
        int i = nums.size()-1;
        int last = i;
        while(i)
        {
            if(nums[i] == nums[i-1])
            {
                nums[i] = nums[last--];
            }
            i--;
        }
        
        return last;
        
}

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2}; // Input array
    int val = 2; // Value to remove
    vector<int> expectedNums = {0,1,4,0,3}; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

    int k = removeDuplicates(nums); // Calls your implementation

    assert(k == expectedNums.size());
    sort(nums.begin(),nums.begin()+k); // Sort the first k elements of nums
    for (int i = 0; i < expectedNums.size(); i++) {
        assert(nums[i] == expectedNums[i]);
    }       
        return 0;
    }
