/*You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.


Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6


Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104*/
#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &prices, int ind, int fee, vector<vector<int>> &dp, int buy)
{
    if (ind == prices.size())
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
        return dp[ind][buy] = max(recur(prices, ind + 1, fee, dp, 0) - prices[ind], recur(prices, ind + 1, fee, dp, 1));
    else
        return dp[ind][buy] = max(recur(prices, ind + 1, fee, dp, 1) + prices[ind] - fee, recur(prices, ind + 1, fee, dp, 0));
}
int maxProfit(vector<int> &prices, int fee)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return recur(prices, 0, fee, dp, 1);
}
int maxProfit1(vector<int> &arr, int fee)
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
                dp[i][buy] = max(dp[i + 1][1] + arr[i] - fee, dp[i + 1][0]);
        }
    }
    return dp[0][1];
}
int maxProfit2(vector<int> &arr, int fee)
{
    int n = arr.size();
    vector<int> ahead(2, 0), cur(2, 0);
    ahead[0] = ahead[1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cur[1] = max(ahead[0] - arr[i], ahead[1]);
        cur[0] = max(ahead[1] + arr[i] - fee, ahead[0]);
        ahead = cur;
    }
    return cur[1];
}
int main()
{
    // Your code here
    return 0;
}