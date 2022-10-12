/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105*/

#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> arr, int ind, int buy, int count, vector<vector<vector<int>>> &dp)
{
    if (ind == arr.size() || count == 0)
        return 0;
    if (dp[ind][buy][count] != -1)
        return dp[ind][buy][count];
    if (buy)
        return dp[ind][buy][count] = max(recur(arr, ind + 1, 0, count, dp) - arr[ind], recur(arr, ind + 1, 1, count, dp));
    else
        return dp[ind][buy][count] = max(recur(arr, ind + 1, 1, count - 1, dp) + arr[ind], recur(arr, ind + 1, 0, count, dp));
}
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return recur(arr, 0, 1, 2, dp);
}
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int count = 1; count <= 2; count++)
            {
                if (buy == 1)
                    dp[i][buy][count] = max(dp[i + 1][buy - 1][count] - arr[i], dp[i + 1][buy][count]);
                else
                    dp[i][buy][count] = max(dp[i + 1][buy + 1][count - 1] + arr[i], dp[i + 1][buy][count]);
            }
        }
    }
    return dp[0][1][2];
}
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int count = 1; count <= 2; count++)
            {
                if (buy == 1)
                    cur[buy][count] = max(ahead[buy - 1][count] - arr[i], ahead[buy][count]);
                else
                    cur[buy][count] = max(ahead[buy + 1][count - 1] + arr[i], ahead[buy][count]);
            }
        }
        ahead = cur;
    }
    return ahead[1][2];
}

int maxProfit(vector<int> &arr)
{
    int buy1 = INT_MAX, buy2 = INT_MAX, profit1 = 0, profit2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        buy1 = min(buy1, arr[i]);              // buying at a low price
        profit1 = max(profit1, arr[i] - buy1); // making higher profit
        buy2 = min(buy2, arr[i] - profit1);    // buying the stock by using the profit
        profit2 = max(profit2, arr[i] - buy2); // now calculating the total profit by decreasing the buy2, which also constitutes buy1
    }
    return profit2;
}

int main()
{
}