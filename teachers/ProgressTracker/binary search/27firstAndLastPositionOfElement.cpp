#include <bits/stdc++.h>
using namespace std;
int firstpos(vector<int> &arr, int target)
{
    int l = 0, h = arr.size() - 1, ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            h = mid - 1;
        }
        else if (arr[mid] > target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return ans;
}
int lastpos(vector<int> &arr, int target)
{
    int l = 0, h = arr.size() - 1, ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (arr[mid] > target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return ans;
}
vector<int> searchRange(vector<int> &arr, int target)
{
    return {firstpos(arr, target), lastpos(arr, target)};
}