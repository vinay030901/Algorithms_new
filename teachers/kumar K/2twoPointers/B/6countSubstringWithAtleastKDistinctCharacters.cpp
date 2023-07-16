/*
Given a string S consisting of N characters and a positive integer K, the task is to count the number of substrings having at least K distinct characters.

Examples:

Input: S = “abcca”, K = 3
Output: 4
Explanation:
The substrings that contain at least K(= 3) distinct characters are:

“abc”: Count of distinct characters = 3.
“abcc”: Count of distinct characters = 3.
“abcca”: Count of distinct characters = 3.
“bcca”: Count of distinct characters = 3.
Therefore, the total count of substrings is 4.


Input: S = “abcca”, K = 4
Output: 0*/
#include <bits/stdc++.h>
using namespace std;
int atleastKDistinctCharacter(string &s, int k)
{
    int n = s.length(), left = 0, right = 0, ans = 0;
    unordered_map<char, int> mp;
    while (right < n)
    {
        mp[s[right++]]++;
        while (mp.size() >= k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
                mp.erase(s[left]);
            ans += right - left + 1;
            left++;
        }
        right++;
    }
    return ans;
}