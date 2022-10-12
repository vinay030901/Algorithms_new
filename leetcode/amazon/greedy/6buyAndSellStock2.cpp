#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    // the first and foremost method is using the approach of buy on one day when cost is high on next day
    // it sounds ridiculous, but it works well
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices[i] > prices[i - 1])
            profit += (prices[i] - prices[i - 1]);
    return profit;
}

// memoization approach here
int fun(vector<int> &arr, int i, int n, int buy, vector<vector<int>> dp)
{
    if (i == n)
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    int profit = 0;
    // so here we have a single important condition, which is that whether we sell the stock or buy or leave it
    // another important aspect is that if we have bought one stock,we can't buy another, we can sell it or leave it
    // so we will have a variable buy, which will change on whether we have any stock at present or not

    if (buy)
        // this is the conditon when we buy the stock or leave it, amoount/profit will decrease when buying
        dp[i][buy] = max(fun(arr, i + 1, n, 0, dp) - arr[i], fun(arr, i + 1, n, 1, dp));
    else
    {
        // this is the conditon when we sell the stock or leave it, amoount/profit will increase when buying
        dp[i][buy] = max(fun(arr, i + 1, n, 1, dp) + arr[i], fun(arr, i + 1, n, 0, dp));
    }
    return dp[i][buy];
}
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, (vector<int>(2, -1)));
    return fun(arr, 0, n, 1, dp);
}

// tabulation approach
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, (vector<int>(2, 0)));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy)
                // this is the conditon when we buy the stock or leave it, amoount/profit will decrease when buying
                dp[i][buy] = max(dp[i + 1][0] - arr[i], dp[i + 1][1]);
            else
            {
                // this is the conditon when we sell the stock or leave it, amoount/profit will increase when buying
                dp[i][buy] = max(dp[i + 1][1] + arr[i], dp[i + 1][0]);
            }
        }
    }
    return dp[0][1];
}

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ahead(2, 0), cur(2, 0);
    ahead[0] = ahead[1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy)
                // this is the conditon when we buy the stock or leave it, amoount/profit will decrease when buying
                profit = max(ahead[0] - arr[i], ahead[1]);
            else
            {
                // this is the conditon when we sell the stock or leave it, amoount/profit will increase when buying
                profit = max(ahead[1] + arr[i], ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return ahead[1];
}
int main()
{
}