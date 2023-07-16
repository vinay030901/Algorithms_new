/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]*/
#include <bits/stdc++.h>
using namespace std;
int findPos(vector<int> &arr, int target, bool first)
{
    int l = 0, h = arr.size() - 1, ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            first == true ? h = mid - 1 : l = mid + 1;
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
    return {findPos(arr, target, true), findPos(arr, target, false)};
}
int main()
{

    return 0;
}