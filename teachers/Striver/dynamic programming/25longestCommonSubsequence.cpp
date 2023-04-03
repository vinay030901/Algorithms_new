/*
Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000
*/

#include <bits/stdc++.h>
using namespace std;

int recur(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n] == s2[m])
        return dp[n][m] = 1 + recur(s1, s2, n - 1, m - 1, dp);
    else
    {
        return dp[n][m] = max(recur(s1, s2, n - 1, m, dp), recur(s1, s2, n, m - 1, dp));
    }
}
int longestCommonSubstr(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return recur(s1, s2, n - 1, m - 1, dp);
}

int longestCommonSubstrTabulation(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        if (s2[0] == s1[i])
            dp[i][0] = 1;
    for (int i = 0; i < m; i++)
        if (s1[0] == s2[i])
            dp[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n - 1][m - 1];
}

int longestCommonSubstrTabulation(string s1, string s2, int n, int m)
{
    
}

int main()
{
}