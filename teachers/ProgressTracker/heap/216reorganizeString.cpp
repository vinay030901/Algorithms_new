/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""*/
#include <bits/stdc++.h>
using namespace std;
string reorganizeString(string str)
{
    int n = str.size();
    string ans = "";
    unordered_map<char, int> mp;
    for (auto st : str)
    {
        mp[st] += 1;
    }
    priority_queue<pair<int, char>> pq;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }
    int mx = pq.top().first;
    if (mx > n / 2 + 1)
        return "";
    while (pq.size() > 1)
    {
        auto p1 = pq.top();
        pq.pop();
        auto p2 = pq.top();
        pq.pop();
        ans += p1.second;
        ans += p2.second;
        p1.first -= 1;
        p2.first -= 1;
        if (p1.first > 0)
            pq.push(p1);
        if (p2.first > 0)
            pq.push(p2);
    }
    if (!pq.empty())
    {
        if (pq.top().first > 1)
            return "";
        else
            ans += pq.top().second;
    }
    return ans;
}
int main()
{

    return 0;
}