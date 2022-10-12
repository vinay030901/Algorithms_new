/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?*/

#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int ind, int prev_ind, vector<vector<int>> &dp)
{
    if (ind == arr.size())
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
        return dp[ind][prev_ind + 1] = max(1 + recur(arr, ind + 1, ind, dp), recur(arr, ind + 1, prev_ind, dp));
    else
        return dp[ind][prev_ind + 1] = recur(arr, ind + 1, prev_ind, dp);
}
int lengthOfLIS(vector<int> &arr)
{
    // here we are sending -1 as the prev_ind, so above
    // we will put prev_ind+1 instead of prev_ind in our 2D vector
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));
    return recur(arr, 0, -1, dp);
}

int lengthOfLIS(vector<int> &arr)
{
    // here we are sending -1 as the prev_ind, so above
    // we will put prev_ind+1 instead of prev_ind in our 2D vector
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, 0));
    int n = arr.size();

    // one thing we should keep in mind is that all of the previous values are shifted by 1
    // so whenever we are are assigning something or using it in the dp vector, we must add 1 to index
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = i - 1; prev >= -1; prev--)
        {
            if (prev == -1 || arr[i] > arr[prev])
                dp[i][prev + 1] = max(1 + dp[i + 1][i + 1], dp[i + 1][prev + 1]);
            else
                dp[i][prev + 1] = dp[i + 1][prev + 1];
        }
    }
    return dp[0][0];
}

int lengthOfLIS(vector<int> &arr)
{
    // here we are sending -1 as the prev_ind, so above
    // we will put prev_ind+1 instead of prev_ind in our 2D vector
    vector<int> ahead(arr.size() + 1, 0), cur(arr.size() + 1, 0);
    int n = arr.size();

    // one thing we should keep in mind is that all of the previous values are shifted by 1
    // so whenever we are are assigning something or using it in the dp vector, we must add 1 to index
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = i - 1; prev >= -1; prev--)
        {
            if (prev == -1 || arr[i] > arr[prev])
                cur[prev + 1] = max(1 + ahead[i + 1], ahead[prev + 1]);
            else
                cur[prev + 1] = ahead[prev + 1];
        }
        ahead = cur;
    }
    return ahead[0];
}

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                lis[i] = max(lis[i], lis[j] + 1);
    return *max_element(lis.begin(), lis.end());
}

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    
}
int main()
{
}