/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.



Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag


Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.*/

#include <bits/stdc++.h>
using namespace std;
int recur(string s, string t, int m, int n, vector<vector<int>> &dp)
{
    // base case is important here. If n value goes less than 0, means it matched all the previous characters, so we return 1
    if (n == 0)
        return 1;
    if (m == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];
    // so the approach here is simple, if the value matches, we will decrease both length or we will let the present value
    // same and check with the next value
    if (s[m] == t[n])
        return dp[m][n] = recur(s, t, m - 1, n - 1, dp) + recur(s, t, m - 1, n, dp);
    else
        return dp[m][n] = recur(s, t, m - 1, n, dp);
}
int numDistinct(string s, string t)
{
    int m = s.length(), n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return recur(s, t, m - 1, n - 1, dp);
}

int numDistinctTabulation(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

    for (int i = 0; i <= n; i++) // whenever j is 0, value is 1 there, or n goes less than 0, means we got correct output that's 1
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return (int)dp[n][m];
}

int numDistinctSpace(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<double> vec(m + 1, 0);

    vec[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
                vec[j] = vec[j - 1] + vec[j];
        }
    }
    return (int)vec[m];
}
int main()
{
}