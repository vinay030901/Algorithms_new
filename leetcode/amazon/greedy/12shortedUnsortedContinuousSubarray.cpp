/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in
ascending order, then the whole array will be sorted in ascending order.

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
    // the simple solution of this just to create the copy of the array, then sort the array
    // later we will check when first value changed and when last value is changed
    // we can then return the answer
    // it is done in O(NLogN) time
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = arr.size();
    int i, j;
    vector<int> a = arr;
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++)
        if (a[i] != arr[i])
            break;
    for (j = n - 1; j >= i; j--)
        if (a[j] != arr[j])
            break;
    return j - i + 1;
}
int findUnsortedSubarray(vector<int> &arr)
{
    // another important method which can solve this question in linear time is finding the minmum and max number where
    // the number is either bigger than its forward or less than it previous
    int mx = INT_MIN, mn = INT_MAX;
    int n = arr.size() - 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] > arr[i + 1])
            {
                mx = max(mx, arr[i]);
                mn = min(mn, arr[i]);
            }
        }
        else if (i == n - 1)
        {
            if (arr[i] < arr[i - 1])
            {
                mx = max(mx, arr[i]);
                mn = min(mn, arr[i]);
            }
        }
        else if (arr[i] > arr[i + 1] || arr[i] < arr[i - 1])
        {
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }
    }
    if (mx == INT_MIN || mn == INT_MAX)
        return 0;
    int i = 0, j = n - 1;
    while (i < n && arr[i] <= mn)
        i++;
    while (j >= 0 && arr[j] >= mx)
        j--;
    return j - i + 1;
}
int main()
{
}