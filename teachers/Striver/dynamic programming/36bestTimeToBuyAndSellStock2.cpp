/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.


Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104*/

#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int n, int bought, vector<vector<int>> &dp)
{
    if (n == arr.size())
        return 0;
    if (dp[n][bought] != -1)
        return dp[n][bought];
    if (bought == 1)
        return dp[n][bought] = max(recur(arr, n + 1, 0, dp) - arr[n], recur(arr, n + 1, 1, dp));
    else
        return dp[n][bought] = max(recur(arr, n + 1, 1, dp) + arr[n], recur(arr, n + 1, 0, dp));
}
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return recur(arr, 0, 1, dp);
}
int maxProfitTabulation(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    int bought = 1;
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
                dp[i][j] = max(dp[i + 1][j - 1] - arr[i], dp[i + 1][j]);
            else
                dp[i][j] = max(dp[i + 1][j + 1] + arr[i], dp[i + 1][j]);
        }
    }
    return dp[0][1];
}
int maxProfitSpace(vector<int> arr)
{
    int n = arr.size();
    vector<int> ahead(2, 0), cur(2, 0);
    ahead[0] = ahead[1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cur[1] = max(ahead[0] - arr[i], ahead[1]);
        cur[0] = max(ahead[1] + arr[i], ahead[0]);
        ahead = cur;
    }
    return cur[1];
}
int maxProfit(vector<int> &arr)
{
    int profit = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i - 1])
            profit += (arr[i] - arr[i - 1]);
    }
    return profit;
}
int main()
{
}