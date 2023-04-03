#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int n, int bought, vector<vector<int>> &dp, int fee)
{
    if (n == arr.size())
        return 0;
    if (dp[n][bought] != -1)
        return dp[n][bought];
    if (bought == 1)
        return dp[n][bought] = max(recur(arr, n + 1, 0, dp, fee) - arr[n], recur(arr, n + 1, 1, dp, fee));
    else
        return dp[n][bought] = max(recur(arr, n + 1, 1, dp, fee) + arr[n] - fee, recur(arr, n + 1, 0, dp, fee));
}
int maxProfit(vector<int> &arr, int fee)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return recur(arr, 0, 1, dp, fee);
}
int maxProfitTabulation(vector<int> arr, int fee)
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
                dp[i][j] = max(dp[i + 1][j + 1] + arr[i] - fee, dp[i + 1][j]);
        }
    }
    return dp[0][1];
}
int maxProfitSpace(vector<int> arr, int fee)
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