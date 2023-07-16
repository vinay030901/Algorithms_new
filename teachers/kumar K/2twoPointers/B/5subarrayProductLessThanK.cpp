/*
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0*/
#include <bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int> &arr, int k)
{
    if (k == 0)
        return 0;
    long long start = 0, end = 0, n = arr.size(), ans = 0, pro = 1;
    while (end < n)
    {
        pro *= arr[end];
        while (start <= end && pro >= k)
        {
            pro /= arr[start++];
        }
        ans += (end - start + 1);
        end++;
    }
    return ans;
}