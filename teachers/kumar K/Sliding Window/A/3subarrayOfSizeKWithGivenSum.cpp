/*
Given an array arr[], an integer K and a Sum. The task is to check if there exists any subarray with K elements whose sum is equal to the given sum. If any of the subarray with size K has the sum equal to the given sum then print YES otherwise print NO.

Examples:

Input: arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}
        k = 4, sum = 18
Output: YES
Subarray = {4, 2, 10, 2}

Input: arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}
        k = 3, sum = 6
Output: YES*/
#include <bits/stdc++.h>
using namespace std;
bool checkSubarraySum(int arr[], int n, int k, int s)
{
    long sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    ans = sum;
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];
        if (sum == s)
            return true;
    }
    return false;
}