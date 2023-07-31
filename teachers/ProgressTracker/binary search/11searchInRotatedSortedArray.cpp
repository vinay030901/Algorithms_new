#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &arr, int target)
{
    int l = 0, h = arr.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] >= arr[l])
        {
            if (arr[mid] >= target && target >= arr[l])
                h = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (arr[h] >= target && target >= arr[mid])
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
    return -1;
}