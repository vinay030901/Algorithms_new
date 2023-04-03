/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order,
then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.



Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0*/
#include <bits/stdc++.h>
using namespace std;
int findUnsortedSubarray(vector<int> &arr)
{
    vector<int> prev = arr;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int first = -1, second = -1;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] != prev[i])
        {
            first = i;
            break;
        }
    for (int i = n - 1; i >= 0; i--)
        if (arr[i] != prev[i])
        {
            second = i;
            break;
        }
    if (second == -1 || first == -1)
        return 0;
    return second - first + 1;
}
int main()
{
}