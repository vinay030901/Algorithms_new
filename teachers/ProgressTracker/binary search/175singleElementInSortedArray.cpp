#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &arr)
{
    int l = 0, h = arr.size() - 1;
    if (h == 0)
        return arr[h];
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if ((mid & 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
            l = mid + 1;
        else
            h = mid - 1;
    }
    return arr[l];
}