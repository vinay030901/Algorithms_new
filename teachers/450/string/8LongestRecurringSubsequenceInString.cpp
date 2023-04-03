/*
Given a string, find the length of the longest repeating subsequence such that the two subsequences
don’t have same string character at the same position, i.e., any i’th character in the two subsequences
shouldn’t have the same index in the original string.

INPUT: STR="AABEBCDD"
        OUTPUT=3
*/
#include <bits/stdc++.h>
using namespace std;
int LongestRecurringSubsequence(string str, int n)
{
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    string s = str;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if ((str[i - 1] == s[j - 1]) && (i != j))
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[n][n];
}
int main()
{
    string str = "abaccdb";
    // longest recurring subsequence is a variation of longest common subsequence

    /*In this variation it is obvious we will compare str with its own, but instead of taking
    all the characters as common, we will ignore the ones having the same indices, so that it doesn't give
    answer as the length of string itself.

    so for str="abeabcdd", ans="abd" because a,b,d are the only characters which appear again, or the characters
    which are on two different indices

    we will use our bottom approach for this rather than recursion or top down*/
    int n = str.length();
    cout << LongestRecurringSubsequence(str, n);
}