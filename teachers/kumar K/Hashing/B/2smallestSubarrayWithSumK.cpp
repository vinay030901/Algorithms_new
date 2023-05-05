/*
here we will store the index of the sum rather than frequency of that value, in that way we will store only the latest
occurenec of that element in our array
then we just find the position where we have encountered sum-k and then if difference between i and that position is less
that ans*/
/*
Given an array arr[] consisting of N integers, the task is to find the length of the Smallest subarray with a sum equal to K.

Examples:

Input: arr[] = {2, 4, 6, 10, 2, 1}, K = 12
Output: 2
Explanation: All possible subarrays with sum 12 are {2, 4, 6} and {10, 2}.

Input: arr[] = {-8, -8, -3, 8}, K = 5
Output: 2*/

#include <bits/stdc++.h>
using namespace std;
int findSubArraySum(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[sum] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp.find(sum - k) != mp.end())
            ans = min(ans, i - mp[sum - k]);
        mp[sum] = i;
    }
    return ans;
}