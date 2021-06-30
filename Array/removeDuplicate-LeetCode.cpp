#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
        
    if(nums.size()<2)
        return nums.size();
        
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
        
    last++;
    sort(nums.begin(),nums.begin()+last);
    return last;
        
}

int main()
{
    vector<int> nums = {1,1,2,2,2}; // Input array
    vector<int> expectedNums = {1,2}; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

    int k = removeDuplicates(nums); // Calls your implementation

    assert(k == expectedNums.size());
    for (int i = 0; i < expectedNums.size(); i++) {
        assert(nums[i] == expectedNums[i]);
    }       
        return 0;
    }
