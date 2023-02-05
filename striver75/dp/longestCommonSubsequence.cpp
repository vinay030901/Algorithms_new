#include <bits/stdc++.h>
using namespace std;
int recur(string &s, string &t, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s[n] == t[m])
        return dp[n][m] = 1 + recur(s, t, n - 1, m - 1, dp);
    else
        return dp[n][m] = max(recur(s, t, n - 1, m, dp), recur(s, t, n, m - 1, dp));
}
int longestCommonSubsequence(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return recur(s, t, n - 1, m - 1, dp);
}
int main()
{
}