/*
You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.

A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.
Example 2:

Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
Example 3:

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER". */
#include <bits/stdc++.h>
using namespace std;
int balancedString(string s)
{
    unordered_map<char, int> mp;
    for (auto &it : s)
        mp[it]++;
    int n = s.length() / 4, res = INT_MAX;
    for (int j = 0, i = 0; j < s.length(); j++)
    {
        mp[s[j]]--;
        while (n >= mp['Q'] && n >= mp['W'] && n >= mp['E'] && n >= mp['R'] && i < s.length())
        {
            res = min(res, j - i + 1);
            ++mp[s[i++]];
        }
    }
    return res;
}