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
    vector<int> dp(n + 1, -1);
    for (int i = 1; i <= 3; i++)
        dp[i] = i;
    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}