/*
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.
Example 1:

Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
Example 2:

Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.*/
#include <bits/stdc++.h>
using namespace std;
class MountainArray
{
public:
    int get(int index);
    int length();
};
int binary_search(MountainArray &arr, int l, int h, int target, bool asc)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int val = arr.get(mid);
        if (val == target)
            return mid;
        if (asc == val < target)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}
// the solution is simple, first you find peak of the element and then you can do binary search on left and right of the peak element to find the target
int findInMountainArray(int target, MountainArray &arr)
{
    int h = arr.length() - 1, peak = 0;
    while (peak < h)
    {
        int mid = peak + (h - peak) / 2;
        if (arr.get(mid) > arr.get(mid + 1))
            h = mid;
        else
            peak = mid + 1;
    }
    if (arr.get(peak) == target)
        return peak;
    int ans = binary_search(arr, 0, peak - 1, target, true);
    return ans != -1 ? ans : binary_search(arr, peak + 1, arr.length() - 1, target, false);
}
int main()
{

    return 0;
}