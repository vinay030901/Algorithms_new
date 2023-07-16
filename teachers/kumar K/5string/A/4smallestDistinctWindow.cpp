/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.



Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"

Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"*/
/*same logic as minimum window substring*/
#include <bits/stdc++.h>
using namespace std;
int findSubString(string str)
{
    // Your code goes here
    string chars = "";
    unordered_map<char, int> mp;
    for (auto it : str)
        if (mp.find(it) == mp.end())
        {
            chars += it;
            mp[it] = 0;
        }
    // cout<<chars;
    int cnt = chars.length(), left = 0, right = 0, n = str.length(), mn = INT_MAX;
    for (auto it : chars)
        mp[it]++;
    while (right < n)
    {
        mp[str[right]]--;
        if (mp[str[right]] >= 0)
            cnt--;
        while (left <= right && cnt == 0)
        {
            mn = min(mn, right - left + 1);
            if (++mp[str[left++]] > 0)
                cnt++;
        }
        right++;
    }
    return mn;
}