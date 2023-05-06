#include <bits/stdc++.h>
using namespace std;
long maximumSumSubarray(int k, vector<int> &arr, int n)
{
    long sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    ans = sum;
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];
        ans = max(ans, sum);
    }
    return ans;
}