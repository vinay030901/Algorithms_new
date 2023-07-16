/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false*/
#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &arr, int target)
{
    int l = 0, h = arr.size() * arr[0].size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int val = arr[mid / arr[0].size()][mid % arr[0].size()];
        if (val == target)
            return true;
        else if (val > target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
int main()
{

    return 0;
}