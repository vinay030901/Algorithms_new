#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int rmx = 0, lmx = 0, n = arr.size(), ans = 0;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            rmx = max(rmx, arr[n - i - 1]);
            lmx = max(lmx, arr[i]);
            left[i] = lmx;
            right[n - i - 1] = rmx;
        }
        for (int i = 0; i < n; i++)
        {
            ans += min(left[i], right[i]) - arr[i];
        }
        return ans;
    }
};