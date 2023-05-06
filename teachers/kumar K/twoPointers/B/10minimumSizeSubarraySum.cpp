/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.



Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0*/
#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &arr)
{
    int n = arr.size(), left = 0, right = 0, mn = INT_MAX, sum = 0;
    while (right < n)
    {
        sum += arr[right];
        while (left <= right && sum >= target)
        {
            if (mn > right - left + 1)
                mn = right - left + 1;
            sum -= arr[left++];
        }
        right++;
    }
    return mn == INT_MAX ? 0 : mn;
}