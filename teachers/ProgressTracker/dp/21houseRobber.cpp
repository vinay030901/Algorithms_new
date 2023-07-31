#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return arr[0];
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max(arr[n] + fun(arr, n - 2, dp), fun(arr, n - 1, dp));
}
int rob(vector<int> &arr)
{
    vector<int> dp(arr.size(), -1);
    return fun(arr, arr.size() - 1, dp);
}

int rob(vector<int> &arr)
{
    vector<int> dp(arr.size(), -1);
    dp[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int left, right;
        left = arr[i];
        if (i > 1)
            left += dp[i - 2];
        right = dp[i - 1];
        dp[i] = max(left, right);
    }
    return dp[arr.size() - 1];
}