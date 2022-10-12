/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={2,1,4,7,3,2,5};
    int n=arr.size();

    // the basic brute force approach is to check for every element and run a loop for it, to find the length of the mountain

    int mx=0;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]<=arr[i-1] || arr[i]<=arr[i+1]) // here if the array value is less than either previous or next, then we will continue
        continue;
        int m=i,o=i-1,cnt=0;
        while(o>=0 && arr[m]>arr[o])// else we will check the length till our array is greater than the previous value
        {
            m--;
            o--;
            cnt+=1;
        }
        m=i;
        o=i+1;
        while(o<n && arr[m]>arr[o])// and we check till the present is greater than previous element
        {
            m++;
            o++;
            cnt+=1;
        }
        if(cnt==0) continue;
        mx=max(cnt+1,mx);
    }
    cout<<mx;
}