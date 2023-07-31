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