/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;
int countSubstrings(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    int cnt = n;
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i == 1 || dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
    return cnt;
}
int main()
{
    // Your code here
    return 0;
}