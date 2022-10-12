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
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;
int recur(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
        return dp[n][m] = recur(s1, s2, n - 1, m - 1, dp);
    else
        return dp[n][m] = 1 + min(recur(s1, s2, n - 1, m, dp), min(recur(s1, s2, n, m - 1, dp), recur(s1, s2, n - 1, m - 1, dp)));
    //                            delete                                 insert                            replace

    /*
    the above logic is if s1="horse" and s2="ros"
    then delete means deleting h, so decrease in n- (n-1,m)
    then insertion means insert r, so r and r matches in s1 ans s2, so s2 length decrease now- (n,m-1)
    and replace means both become same and therefore both decrease- (n-1,m-1)*/
}
int minDistance(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return recur(s1, s2, n, m, dp);
}

int minDistanceTabulation(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
    return dp[n][m];
}

int minDistanceSpace(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for(int j=0;j<=m;j++) prev[j] =j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)

            if (j == 0)
                cur[j] = i;
            else if (s1[i - 1] == s2[j - 1])
                cur[j] = prev[j - 1];
            else
                cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j - 1]));
        prev = cur;
    }

    return prev[m];
}
int main()
{
}