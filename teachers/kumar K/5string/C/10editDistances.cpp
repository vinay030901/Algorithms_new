/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')*/
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
int main()
{

    return 0;
}