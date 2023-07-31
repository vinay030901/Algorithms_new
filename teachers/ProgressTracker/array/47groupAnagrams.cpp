#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<map<char, int>, vector<string>> mp;
    vector<vector<string>> ans;
    for (auto str : strs)
    {
        map<char, int> mstr;
        for (auto it : str)
            mstr[it] += 1;
        mp[mstr].push_back(str);
    }
    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}