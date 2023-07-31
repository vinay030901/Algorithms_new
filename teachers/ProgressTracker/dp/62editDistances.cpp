#include <bits/stdc++.h>
using namespace std;
int recur(string &str1, int n, string &str2, int m, vector<vector<int>> &dp)
{
    if (m <= 0)
        return n;
    if (n <= 0)
        return m;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (str1[n - 1] == str2[m - 1])
        return dp[n][m] = recur(str1, n - 1, str2, m - 1, dp);
    return dp[n][m] = 1 + min(recur(str1, n - 1, str2, m - 1, dp), min(recur(str1, n - 1, str2, m, dp), recur(str1, n, str2, m - 1, dp)));
}
int minDistance(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return recur(str1, n, str2, m, dp);
}