/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input:
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the
longest palindromes with same length.
The result is the one with the least
starting index.*/
#include <bits/stdc++.h>
using namespace std;
string longestPalin(string s)
{
    // code here
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    int start = 0, len = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i == 1 || dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                    if (j - i + 1 >= len)
                    {
                        len = j - i + 1;
                        start = i;
                    }
                }
            }
        }
    return s.substr(start, len);
}
int main()
{
    return 0;
}