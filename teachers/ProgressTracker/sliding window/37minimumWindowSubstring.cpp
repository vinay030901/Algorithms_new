#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    for (auto it : t)
        mp[it]++;
    int cnt = t.length(), mn_start, mn = INT_MAX, right = 0, left = 0, n = s.length();
    while (right < n)
    {
        if (mp[s[right]]-- > 0)
        {
            cnt--;
        }
        while (left <= right && cnt == 0)
        {
            if (mn > right - left + 1)
            {
                mn = right - left + 1;
                mn_start = left;
            }
            if (++mp[s[left++]] > 0)
                cnt++;
        }
        right++;
    }
    return mn == INT_MAX ? "" : s.substr(mn_start, mn);
}