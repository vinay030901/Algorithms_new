#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, n = s.length(), arr[256] = {0}, mx = 0;
        while (right < n)
        {
            if (arr[s[right]] == 0)
            {
                arr[s[right++]]++;
                mx = max(mx, right - left);
            }
            else
                --arr[s[left++]];
        }
        return mx;
    }
};