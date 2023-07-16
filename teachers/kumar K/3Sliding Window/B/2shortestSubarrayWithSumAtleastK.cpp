/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3*/
#include <bits/stdc++.h>
using namespace std;
int shortestSubarray(vector<int> &arr, int k)
{
    // try for example: 2 7 3 -8 4 10
    deque<long> dq;
    long n = arr.size(), mn = arr.size() + 1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            arr[i] += arr[i - 1];
        if (arr[i] >= k)
            mn = min(mn, (long)i + 1);
        while (dq.size() && arr[i] <= arr[dq.back()])
            dq.pop_back();
        while (dq.size() && arr[i] - arr[dq.front()] >= k)
            mn = min(mn, i - dq.front() + 1), dq.pop_front();
        dq.push_back(i);
    }
    return mn <= n ? mn : -1;
}