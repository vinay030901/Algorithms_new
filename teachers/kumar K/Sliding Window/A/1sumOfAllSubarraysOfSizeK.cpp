/*
Given an array arr[] and an integer K, the task is to calculate the sum of all subarrays of size K.

Examples:

Input: arr[] = {1, 2, 3, 4, 5, 6}, K = 3
Output: 6 9 12 15
Explanation:
All subarrays of size k and their sum:
Subarray 1: {1, 2, 3} = 1 + 2 + 3 = 6
Subarray 2: {2, 3, 4} = 2 + 3 + 4 = 9
Subarray 3: {3, 4, 5} = 3 + 4 + 5 = 12
Subarray 4: {4, 5, 6} = 4 + 5 + 6 = 15

Input: arr[] = {1, -2, 3, -4, 5, 6}, K = 2
Output: -1, 1, -1, 1, 11
Explanation:
All subarrays of size K and their sum:
Subarray 1: {1, -2} = 1 – 2 = -1
Subarray 2: {-2, 3} = -2 + 3 = -1
Subarray 3: {3, 4} = 3 – 4 = -1
Subarray 4: {-4, 5} = -4 + 5 = 1
Subarray 5: {5, 6} = 5 + 6 = 11 */
#include <bits/stdc++.h>
using namespace std;
int calcSum(int arr[], int n, int k)
{
    int sum = 0, s = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    for (int i = k; i < n; i++)
    {
        s -= arr[i - k] + arr[i];
        sum += s;
    }
    return sum;
}