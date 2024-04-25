/*Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.



Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4


Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lcs(string &word1, int n, string &word2, int m, vector<vector<int>> &dp)
    {
        if (n < 0 || m < 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (word1[n] == word2[m])
            return dp[n][m] = 1 + lcs(word1, n - 1, word2, m - 1, dp);
        return dp[n][m] = max(lcs(word1, n - 1, word2, m, dp), lcs(word1, n, word2, m - 1, dp));
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return n + m - 2 * lcs(word1, n - 1, word2, m - 1, dp);
    }
};
int minDistance(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return n + m - 2 * dp[n][m];
}
int main()
{
    // Your code here
    return 0;
}