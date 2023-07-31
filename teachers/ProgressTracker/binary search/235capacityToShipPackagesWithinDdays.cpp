#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &arr, int mid, int days)
{
    int sum = 0, times = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > mid)
            return false;
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            times++;
        }
    }
    return times <= days;
}
int shipWithinDays(vector<int> &arr, int days)
{
    int l = *max_element(arr.begin(), arr.end()), ans, h = accumulate(arr.begin(), arr.end(), 0);
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(arr, mid, days))
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}