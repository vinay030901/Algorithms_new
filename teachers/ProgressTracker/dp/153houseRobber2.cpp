/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000*/
#include <bits/stdc++.h>
using namespace std;
int recur(int i, int n, vector<int> &arr, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (i == n - 1)
        return arr[i];
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = max(arr[i] + recur(i + 2, n, arr, dp), recur(i + 1, n, arr, dp));
}
int rob(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    vector<int> dp(n + 1, -1);
    int a1 = recur(0, n - 1, arr, dp);
    vector<int> p(n + 1, -1);
    int a2 = recur(1, n, arr, p);
    return max(a1, a2);
}
int robSpace(vector<int> &arr, int start, int end)
{
    int prev1 = arr[start], prev2 = 0;
    for (int i = start + 1; i < end; i++)
    {
        int pick = arr[i];
        if (i > start + 1)
            pick += prev2;
        int notPick = prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int rob(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    return max(robSpace(arr, 0, n - 1), robSpace(arr, 1, n));
}
int main()
{
    // Your code here
    return 0;
}