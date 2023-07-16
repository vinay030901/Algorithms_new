/*
Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.*/
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    int cnt = t.size(), mp[256] = {0}, start, mn = INT_MAX, n = s.size(), left = 0, right = 0;
    for (auto it : t)
        mp[it]++;
    while (right < n)
    {
        mp[s[right]]--;
        if (mp[s[right]] >= 0)
        {
            cnt--;
        }
        while (left <= right && cnt == 0)
        {
            if (mn > right - left + 1)
            {
                mn = right - left + 1;
                start = left;
            }
            if (++mp[s[left++]] > 0)
                cnt++;
        }
        right++;
    }
    return mn == INT_MAX ? "" : s.substr(start, mn);
}
