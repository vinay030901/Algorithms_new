#include <bits/stdc++.h>
using namespace std;
int fun(int n, vector<int> &dp)
{
    if (n <= 3)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fun(n - 1, dp) + fun(n - 2, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return fun(n, dp);
}

int climbStairs(int n)
{
    if (n <= 3)
        return n;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i <= 3)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}