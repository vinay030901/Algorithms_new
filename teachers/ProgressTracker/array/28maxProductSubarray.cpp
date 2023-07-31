#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &arr)
{
    int cur = 1, n = arr.size(), mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cur *= arr[i];
        mx = max(mx, cur);
        if (arr[i] == 0)
            cur = 1;
    }
    cur = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        cur *= arr[i];
        mx = max(mx, cur);
        if (arr[i] == 0)
            cur = 1;
    }
    return mx;
}