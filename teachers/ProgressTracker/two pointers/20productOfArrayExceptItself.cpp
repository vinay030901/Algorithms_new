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

vector<int> productExceptSelf(vector<int> &arr)
{
    // we have two methods to do it
    // without using extra space and with extra space
    // first we will use extra space which is a lot easier here
    // we are going to find the prefix and suffix sum in this case
    int n = arr.size();
    vector<int> prefix(n), suffix(n);
    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * arr[i];
        suffix[n - i - 1] = suffix[n - i] * arr[n - i - 1];
    }
    vector<int> ans(n);
    ans[0] = suffix[1];
    ans[n - 1] = prefix[n - 2];
    for (int i = 1; i < n - 1; i++)
    {
        ans[i] = suffix[i + 1] * prefix[i - 1];
    }
    return ans;
}