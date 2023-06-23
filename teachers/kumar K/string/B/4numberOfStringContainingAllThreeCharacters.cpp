/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.



Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
Example 3:

Input: s = "abc"
Output: 1*/
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/solutions/516977/java-c-python-easy-and-concise/?orderBy=most_votes
int atmost(string &s, int k)
{
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
        mx += right - left + 1;
        right++;
    }
    return mx;
}
int numberOfSubstrings(string s)
{
    return atmost(s, 3) - atmost(s, 2);
}