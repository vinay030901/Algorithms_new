#include <bits/stdc++.h>
using namespace std;
int maximumProduct(vector<int> &arr)
{
    int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
    for (auto it : arr)
    {
        if (it > mx1)
        {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = it;
        }
        else if (it > mx2)
        {
            mx3 = mx2;
            mx2 = it;
        }
        else if (it > mx3)
        {
            mx3 = it;
        }
        if (it < mn1)
        {
            mn2 = mn1;
            mn1 = it;
        }
        else if (it < mn2)
            mn2 = it;
    }
    return max(mx1 * mx2 * mx3, mx1 * mn1 * mn2); // this is the main point
}
int maximumProduct(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), greater<int>());
    int mx = arr[2] * arr[1] * arr[0];
    mx = max(mx, arr[0] * arr[arr.size() - 1] * arr[arr.size() - 2]);
    return mx;
}
int main()
{
    // Your code here
    return 0;
}