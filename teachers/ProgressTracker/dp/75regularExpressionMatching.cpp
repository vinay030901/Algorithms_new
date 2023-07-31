#include <bits/stdc++.h>
using namespace std;
bool fun(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (i == s.length() && j == p.length())
        return true;
    if (j == p.length())
        return false;
    bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
    if (j + 1 < p.length() && p[j + 1] == '*')
        return dp[i][j] = (fun(i, j + 2, s, p, dp) || (match && fun(i + 1, j, s, p, dp)));
    if (match)
        return dp[i][j] = fun(i + 1, j + 1, s, p, dp);
    return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    return fun(0, 0, s, p, dp);
}