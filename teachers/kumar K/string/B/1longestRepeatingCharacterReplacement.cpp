/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.



Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.*/

#include <bits/stdc++.h>
using namespace std;
/*
The problem says that we can make at most k changes to the string (any character can be replaced with any other character). So, let's say there were no constraints like the k. Given a string convert it to a string with all same characters with minimal changes. The answer to this is

length of the entire string - number of times of the maximum occurring character in the string

Given this, we can apply the at most k changes constraint and maintain a sliding window such that

(length of substring - number of times of the maximum occurring character in the substring) <= k
this means that everything should be done in the k size substring*/
int characterReplacement(string s, int k)
{
    int mp[26] = {0};
    int mxcount = 0, mx = 0, left = 0;
    for (int right = 0; right < s.length(); right++)
    {
        mxcount = max(mxcount, ++mp[s[right] - 'A']);
        // check the number of characters other than maximum occuf
        while (right - left + 1 - mxcount > k)
        {
            mp[s[left] - 'A']--;
            left++;
        }
        mx = max(mx, right - left + 1);
    }
    return mx;
}