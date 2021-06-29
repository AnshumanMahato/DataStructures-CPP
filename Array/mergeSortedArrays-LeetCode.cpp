#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n)
            return;
        if(!m)
        {
            nums1.clear();
            int i = 0;
            while(i<n)
                nums1.push_back(nums2[i++]);
            return;
        }
        vector<int> first(nums1.begin(),nums1.begin()+m);
        int i=0,j=0,ptr=0;
        while(i < m && j < n)
        {
            if(nums1[i]<=nums2[j])
                nums1[ptr++] = first[i++];
            else
                nums1[ptr++] = nums2[j++];
        }
        
        while(i<m)
        {
            nums1[ptr++] = first[i++];
        }
        
        while(j<n)
        {
            nums1[ptr++] = nums2[j++];
        }
        
}

int main()
{
    vector<int>num1{4,5,6,0,0,0};
    vector<int>num2{1,2,3};
    int m=3,
        n=3;
    merge(num1,m,num2,n);

    for (int i = 0; i < num1.size(); i++)
    {
        cout<<num1[i]<<',';
    }
    
    return 0;
}
