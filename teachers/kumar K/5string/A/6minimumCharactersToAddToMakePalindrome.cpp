/*
Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

Example 1:

Input:
S = "abc"
Output: 2
Explanation:
Add 'b' and 'c' at front of above string to make it
palindrome : "cbabc"
Example 2:

Input:
S = "aacecaaa"
Output: 1
Explanation: Add 'a' at front of above string
to make it palindrome : "aaacecaaa"*/
/*this code could be done using the lcs dp, where we can calculate the number of insertion to make it dp
 */
#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2)
int minChar(string str)
{

    long int n = str.length();
    long int maxi = 0;

    string str1 = str;
    reverse(str1.begin(), str1.end());

    vector<vector<long int>> dp(n + 1, vector<long int>(n + 1, 0));

    for (long int i = 1; i <= n; i++)
    {
        for (long int j = 1; j <= n; j++)
        {

            if (str[i - 1] == str1[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }

            maxi = max(maxi, dp[i][j]);
        }
    }

    return n - maxi;
}

// an efficient way to do this using lps array where we will calculate the longest prefix which is also a suffix by c
// concatening the string with itself
// For string = AACECAAAA
// Concatenated String = AACECAAAA$AAAACECAA
// LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2,
//                    0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
int minChar(string str)
{
    string rev = str;
    int m = str.length();
    // we will add the reverse so that we may compare the string in reverse pattern and check for palindrom
    // as in case of lps, the string are compared in straight manner
    reverse(rev.begin(), rev.end());
    str = str + "%" + rev;
    int n = str.length();
    int lps[n];
    lps[0] = 0;
    int i = 1, len = 0;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return m - lps[n - 1];
}

// more easier way using two pointers
int minChar(string str)
{
    int left = 0, right = str.length() - 1, res = 0;
    while (left < right)
    {
        if (str[left] == str[right])
        {
            left++;
            right--;
        }
        else
        {
            res++;
            left = 0;
            right = str.length() - res - 1;
        }
    }
    return res;
}