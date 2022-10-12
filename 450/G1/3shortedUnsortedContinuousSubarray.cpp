/*Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0*/
#include <bits/stdc++.h>
using namespace std;
int findUnsortedSubarray(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n=arr.size();
        int i,j;
        vector<int>a=arr;
        sort(a.begin(),a.end());
        for(i=0;i<n;i++)
            if(a[i]!=arr[i]) break;
        for(j=n-1;j>=i;j--)
            if(a[j]!=arr[j]) break;
        return j-i+1;
    }
int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int Min=INT_MAX;
        int Max=INT_MIN;
        
        // in this approach we tried to find the minimum and maximum number which is unsorted, this will
        if(n==1)
            return 0; 
        
        for(int i=0; i<n; i++)
        {
            if(i==0 )
            {
                if(nums[i]>nums[i+1])
                {
                    Min=min(Min, nums[i]);
                    Max=max(Max, nums[i]);
                }
            }
            else if(i==n-1 )
            {
                if(nums[i]<nums[i-1])
                {
                    Min=min(Min, nums[i]);
                    Max=max(Max, nums[i]);
                }
            }
            else
            {
                if(nums[i]>nums[i+1] || nums[i]<nums[i-1])
                {
                    Min=min(Min, nums[i]);
                    Max=max(Max, nums[i]);
                }
            }            
        }
        
        if(Min==INT_MAX || Max==INT_MIN)
            return 0;
        int i=0,j=n-1;
        while(i<n && nums[i]<=Min)
        i++;
        while(j>=0 && nums[j]>=Max)
        j--;
        return j-i+1;
        
    }
int main()
{
    vector<int>arr = {2,6,4,8,10,9,15};
    cout<<findUnsortedSubarray(arr);
}