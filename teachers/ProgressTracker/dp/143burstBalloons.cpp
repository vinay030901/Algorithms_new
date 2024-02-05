/*You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.



Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10


Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100*/
#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mx = INT_MIN;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + recur(arr, i, k, dp) + recur(arr, k + 1, j, dp);
        mx = max(mx, steps);
    }
    return dp[i][j] = mx;
}
int maxCoins(vector<int> &arr)
{
    arr.insert(arr.begin(), 1);

    arr.push_back(1);
    int n = arr.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    return recur(arr, 1, n - 1, dp);
}
int main()
{
    // Your code here
    return 0;
}