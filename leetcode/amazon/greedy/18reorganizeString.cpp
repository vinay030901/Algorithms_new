/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/
#include <bits/stdc++.h>
using namespace std;
string reorganizeString(string str)
{
    // the solution of this questio is simple
    // since the character shouldn't repeat, one thing we know that is we should place the character which has max frequency first
    /* therefore we are using heap here, we will put all the characters in a map first with the value as their frequency
    then we put it into max heap, which will heapify it according to the frequency
    so we get the max frequency character first
    */
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
        // then we put into our ans and decrease the frequency
        // if frequency is 0, we will not push them back
        ans += p1.second;
        ans += p2.second;
        p1.first -= 1;
        p2.first -= 1;
        if (p1.first > 0)
            pq.push(p1);
        if (p2.first > 0)
            pq.push(p2);
    }

    // if the length of string is odd, we will be remaining with one character here
    // we will check if its frquency is greater than 0 or not, if not we push it into answer and return
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
}