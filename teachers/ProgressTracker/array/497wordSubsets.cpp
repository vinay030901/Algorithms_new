#include <bits/stdc++.h>
using namespace std;
vector<int> mapping(string &str)
{
    vector<int> temp(26);
    for (auto it : str)
        temp[it - 'a']++;
    return temp;
}
vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<int> mx(26, 0);
    vector<string> ans;
    for (auto it : words2)
    {
        vector<int> temp = mapping(it);
        for (int i = 0; i < 26; i++)
            mx[i] = max(mx[i], temp[i]);
    }
    for (auto it : words1)
    {
        vector<int> temp = mapping(it);
        int i = 0;
        for (i = 0; i < 26; i++)
            if (temp[i] < mx[i])
                break;
        if (i == 26)
            ans.push_back(it);
    }
    return ans;
}