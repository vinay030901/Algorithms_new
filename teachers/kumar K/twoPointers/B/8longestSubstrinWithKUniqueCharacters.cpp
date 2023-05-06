/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest
substring with K distinct characters.
Example 2:

Input:
S = "aaaa", K = 2
Output: -1
Explanation: There's no substring with K
distinct characters.*/
#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string s, int k)
{
    int cnt = 0, right = 0, left = 0, n = s.size(), mx = -1, mp[256] = {0};
    while (right < n)
    {
        if (mp[s[right]]++ == 0)
            cnt++;
        while (left <= right && cnt > k)
        {
            mp[s[left]]--;
            if (mp[s[left++]] == 0)
                cnt--;
        }
        if (cnt == k)
            mx = max(mx, right - left + 1);
        right++;
    }
    return mx;
}