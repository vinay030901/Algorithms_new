/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.



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
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.*/

#include <bits/stdc++.h>
using namespace std;
string minimumWindow(string s, string t)
{
    unordered_map<char, int> mp;

    // we will store the test string in a map
    for (auto c : t)
        mp[c]++;
    int left = 0, right = 0, count = t.size(), n = s.size(), mn = INT_MAX, mn_start;
    while (right < n)
    {
        // we will check if this element is present in test string, if it is we will decrease the count of chars found
        if (mp[s[right]] > 0)
            count--;

        mp[s[right]]--;
        while (count == 0)
        {
            if (mn > right - left + 1) // we will update the length
            {
                mn = right - left + 1;
                mn_start = left;
            }

            // now we will increase the value till we have counter as 0 only, so that we may get the minimum value
            mp[s[left]]++;
            // if s[left] was in the test string, it will go over 0 since it was decrease to zero only, so we will increase the counter
            // otherwise the number will not go above zero and therefore we will keep checking till counter is zero
            if (mp[s[left++]] > 0)
                count++;
        }
        right++;
    }
    if (mn != INT_MAX)
        return s.substr(mn_start, mn);
    return "";
}
int main()
{
}