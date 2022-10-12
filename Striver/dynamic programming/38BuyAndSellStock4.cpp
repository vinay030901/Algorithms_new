/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


Constraints:

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000*/

#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int ind, int buy, int k, vector<vector<vector<int>>> &dp)
{
    if (ind == arr.size() || k == 0)
        return 0;
    if (dp[ind][buy][k] != -1)
        return dp[ind][buy][k];
    if (buy)
        return dp[ind][buy][k] = max(recur(arr, ind + 1, 0, k, dp) - arr[ind], recur(arr, ind + 1, 1, k, dp));
    else
        return dp[ind][buy][k] = max(recur(arr, ind + 1, 1, k - 1, dp) + arr[ind], recur(arr, ind + 1, 0, k, dp));
}
int maxProfit(int k, vector<int> &arr)
{
    vector<vector<vector<int>>> dp(arr.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return recur(arr, 0, 1, k, dp);
}
int maxProfit(int k, vector<int> &arr)
{
    vector<vector<vector<int>>> dp(arr.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int count = 1; count <= k; count++)
            {
                if (buy)
                    dp[i][buy][count] = max(dp[i + 1][0][count] - arr[i], dp[i + 1][1][count]);
                else
                    dp[i][buy][count] = max(arr[i] + dp[i + 1][1][count - 1], dp[i + 1][0][count]);
            }
        }
    }
    return dp[0][1][k];
}
int maxProfit(int k, vector<int> &arr)
{
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0)), cur(2, vector<int>(k + 1, 0));
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int count = 1; count <= k; count++)
            {
                if (buy)
                    cur[buy][count] = max(ahead[0][count] - arr[i], ahead[1][count]);
                else
                    cur[buy][count] = max(arr[i] + ahead[1][count - 1], ahead[0][count]);
            }
        }
        ahead = cur;
    }
    return ahead[1][k];
}
int main()
{
}