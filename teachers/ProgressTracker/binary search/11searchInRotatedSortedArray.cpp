#include <bits/stdc++.h>
using namespace std;
// it has two important conditions
// 1. when the middle is bigger than the first element-> means the array is sorted in that part: so we will check if the target is between firt and middle element
// 2. when the middle is smaller than the first element-> means the array is sorted in second half: so we will check for rigtht and middle element
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