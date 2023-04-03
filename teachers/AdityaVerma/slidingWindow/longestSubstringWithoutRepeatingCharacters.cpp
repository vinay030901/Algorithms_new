#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int arr[256] = {0};
        int left = 0, right = 0, mx = 0, count = 0, n = s.length();
        while (right < n)
        {
            if (arr[s[right]] == 0)
            {
                arr[s[right]]++;
                mx = max(mx, right - left + 1);
                right++;
            }
            else
            {
                arr[s[left++]]--;
            }
        }
        return mx;
    }
};
int length(string s)
{
    int n = s.length(), left = 0, right = 0, mx = 0;
    int arr[256] = {0};
    while (right < n)
    {
        if (arr[s[right]] == 0)
        {
            arr[s[right]]++;
            mx = max(mx, right - left - 1);
            right++;
        }
        else
        {
            arr[s[left++]]--;
        }
    }
    return mx;
}
int main()
{
}