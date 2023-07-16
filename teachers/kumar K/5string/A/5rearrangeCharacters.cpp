/*
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : str = "geeksforgeeks"
Output: 1
Explanation: All the repeated characters of the
given string can be rearranged so that no
adjacent characters in the string is equal.
Any correct rearrangement will show a output
of 1.
Example 2:

Input : str = "bbbbb"
Output: 0
Explanation: Repeated characters in the string
cannot be rearranged such that there should not
be any adjacent repeated character.*/
#include <bits/stdc++.h>
using namespace std;
string rearrangeString(string str)
{
    // code here
    int n = str.size();
    unordered_map<char, int> mp;
    for (auto it : str)
        mp[it]++;
    for (auto it : mp)
        if (it.second > n / 2 + 1)
            return "-1";
    priority_queue<pair<int, char>> pq;
    for (auto it : mp)
        pq.push({it.second, it.first});
    string ans = "";
    pair<int, char> prev = {-1, '#'};
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        ans += curr.second;
        curr.first--;
        if (prev.first > 0)
            pq.push(prev);
        prev = curr;
    }
    if (ans.length() != str.length())
        return "-1";
    return ans;
}