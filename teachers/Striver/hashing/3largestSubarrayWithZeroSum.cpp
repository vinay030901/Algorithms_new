/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.*/

#include <bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &arr, int n)
{
    // Your code here
    unordered_map<int, int> mp;
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            mx = i + 1;
        if (mp.find(sum) != mp.end())
            mx = max(mx, i - mp[sum]);
        else
            mp[sum] = i;
    }
    return mx;
}