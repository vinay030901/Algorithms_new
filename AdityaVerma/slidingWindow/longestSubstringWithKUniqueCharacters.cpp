#include <bits/stdc++.h>
using namespace std;
int longestSubstring(string str, int k)
{
    int n = str.length(), mx = -1, left = 0, right = 0, count = 0;
    int arr[256] = {0};
    while (right < n)
    {
        if (arr[str[right]]++ == 0)
            count++;
        if (count == k)
            mx = max(mx, right - left + 1);
        if (count > k)
        {
            while (count > k && left <= right)
            {
                arr[str[left]]--;
                if (arr[str[left++]] == 0)
                    count--;
            }
        }
        right++;
    }
    return mx;
}
int main()
{
}