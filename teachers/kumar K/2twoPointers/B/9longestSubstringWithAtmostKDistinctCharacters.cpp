/*
Given a string S, find the length of the longest substring T that contains at most k distinct characters.

Wechat reply 【Two Sigma】 get the latest requent Interview questions. (wechat id : jiuzhang1104)


Example
Example 1:

Input: S = "eceba" and k = 3
Output: 4
Explanation: T = "eceb"
Example 2:

Input: S = "WORLD" and k = 4
Output: 4
Explanation: T = "WORL" or "ORLD"*/
#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstringKDistinct(string &s, int k)
{
    // write your code here
    int left = 0, right = 0, n = s.length(), mx = 0;
    unordered_map<char, int> mp;
    while (right < n)
    {
        mp[s[right]]++;
        while (left <= right && mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
                mp.erase(s[left]);
            left++;
        }
        mx = max(mx, right - left + 1);
        right++;
    }
    return mx;
}