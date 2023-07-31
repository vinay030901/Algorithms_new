#include <bits/stdc++.h>
using namespace std;
long long fun(vector<int> &arr, int sum, int n, vector<vector<long long>> &dp)
{
    if (sum == 0)
        return 0;
    if (n < 0 || sum < 0)
        return 1e6;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n] <= sum)
        return dp[n][sum] = min(1 + fun(arr, sum - arr[n], n, dp), fun(arr, sum, n - 1, dp));
    else
        return dp[n][sum] = fun(arr, sum, n - 1, dp);
}
int coinChange(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, -1));
    long long ans = fun(arr, sum, arr.size() - 1, dp);
    return ans >= 1e6 ? -1 : ans;
}

int coinChange(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, -1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 1e6;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - arr[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum] >= 1e6 ? -1 : dp[n][sum];
