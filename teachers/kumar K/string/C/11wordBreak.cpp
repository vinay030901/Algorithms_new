/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.
Example 1:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango" }
A = "ilike"
Output:
1
Explanation:
The string can be segmented as "i like".

Example 2:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango" }
A = "ilikesamsung"
Output:
1
Explanation:
The string can be segmented as
"i like samsung" or "i like sam sung".*/
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

    return 0;
}