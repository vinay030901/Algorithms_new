/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1*/
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
        if (arr[mid] > target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{

    return 0;
}