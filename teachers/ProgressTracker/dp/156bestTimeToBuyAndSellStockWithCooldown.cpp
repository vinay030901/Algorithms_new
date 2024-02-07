/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000*/
#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int ind, int buy, vector<vector<int>> &dp)
{
    if (ind >= arr.size())
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
        return dp[ind][buy] = max(recur(arr, ind + 1, 0, dp) - arr[ind], recur(arr, ind + 1, 1, dp));
    else
        return dp[ind][buy] = max(recur(arr, ind + 2, 1, dp) + arr[ind], recur(arr, ind + 1, 0, dp));
}
int maxProfit1(vector<int> &arr)
{
    vector<vector<int>> dp(arr.size() + 1, vector<int>(2, -1));
    return recur(arr, 0, 1, dp);
}
int maxProfit2(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(arr.size() + 2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
                dp[i][buy] = max(dp[i + 1][0] - arr[i], dp[i + 1][1]);
            else
                dp[i][buy] = max(dp[i + 2][1] + arr[i], dp[i + 1][0]);
        }
    }
    return dp[0][1];
}
int maxProfit3(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ahead1(2, 0), ahead2(2, 0), cur(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
                cur[buy] = max(ahead1[0] - arr[i], ahead1[1]);
            else
                cur[buy] = max(ahead2[1] + arr[i], ahead1[0]);
        }
        ahead2 = ahead1;
        ahead1 = cur;
    }
    return ahead1[1];
}
int main()
{
    // Your code here
    return 0;
}