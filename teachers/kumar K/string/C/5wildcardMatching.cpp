/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.*/
#include <bits/stdc++.h>
using namespace std;
bool recur(string &s, string &p, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 && m < 0)
        return true;
    else if (m < 0 && n >= 0)
        return false;
    else if (m >= 0 && n < 0)
    {
        for (int i = 0; i <= m; i++)
            if (p[i] != '*')
                return false;
        return true;
    }
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s[n] == p[m] || p[m] == '?')
        return dp[n][m] = recur(s, p, n - 1, m - 1, dp);
    if (p[m] == '*')
        return dp[n][m] = recur(s, p, n - 1, m, dp) || recur(s, p, n, m - 1, dp);

    return dp[n][m] = false;
}
bool match(string p, string s)
{
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return recur(s, p, n - 1, m - 1, dp);
}
int main()
{

    return 0;
}