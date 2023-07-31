#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> &arr)
{
    int n = arr.size(), left = 1, right = 1;
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        ans[i] *= left;
        ans[n - i - 1] *= right;
        left *= arr[i];
        right *= arr[n - i - 1];
    }
    return ans;
}