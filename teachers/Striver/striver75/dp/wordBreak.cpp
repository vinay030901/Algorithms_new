/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false*/

#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
bool wordBreak(string s, vector<string> &words)
{
    if (find(words.begin(), words.end(), s) != words.end())
        return true;
    if (mp.find(s) != mp.end())
        return mp[s];
    for (int i = 1; i < s.length(); i++)
    {
        string left = s.substr(0, i);
        if (find(words.begin(), words.end(), left) != words.end() && wordBreak(s.substr(i), words))
            return mp[s] = true;
    }
    return mp[s] = false;
}
int main()
{
}