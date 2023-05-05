/*first we initialise a map with all int_max and then we will traverse each string and make its map
then we check all the 26 characters and find the minimum frequency, later we return that minimum frequency*/
/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]*/
#include <bits/stdc++.h>
using namespace std;
vector<string> commonChars(vector<string> &words)
{
    vector<int> cnt(26, INT_MAX);
    for (int i = 0; i < words.size(); i++)
    {
        vector<int> cnt1(26, 0);
        for (auto it : words[i])
            cnt1[it - 'a']++;
        for (int i = 0; i < 26; i++)
            cnt[i] = min(cnt1[i], cnt[i]);
    }
    vector<string> ans;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < cnt[i]; j++)
            ans.push_back(string(1, i + 'a'));
    return ans;
}