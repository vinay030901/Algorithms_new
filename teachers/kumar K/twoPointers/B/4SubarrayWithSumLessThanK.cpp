/*
Given an array of non-negative numbers and a non-negative number k, find the number of subarrays having sum less than k. We may assume that there is no overflow.

Examples :

Input : arr[] = {2, 5, 6}
        K = 10
Output : 4
The subarrays are {2}, {5}, {6} and
{2, 5},

Input : arr[] = {1, 11, 2, 3, 15}
        K = 10
Output : 4
{1}, {2}, {3} and {2, 3}*/
/*
An efficient solution is based on a sliding window technique that can be used to solve the problem. We use two pointers start and end to represent starting and ending points of the sliding window. (Not that we need to find contiguous parts).

Initially both start and endpoint to the beginning of the array, i.e. index 0. Now, let’s try to add a new element el. There are two possible conditions.

1st case :

If sum is less than k, increment end by one position. So contiguous arrays this step produce are (end – start). We also add end to previous sum. There are as many such arrays as the length of the window.
2nd case :

If sum becomes greater than or equal to k, this means we need to subtract starting element from sum so that the sum again becomes less than k. So we adjust the window’s left border by incrementing start.
We follow the same procedure until end < array size.*/
#include <bits/stdc++.h>
using namespace std;
int countSubarrays(int arr[], int n, int k)
{
    int start = 0, end = 0, sum = 0, ans = 0;
    while (start < n && end < n)
    {
        if (sum < k)
        {
            end++;
            if (start < end)
                ans += (end - start);
            if (end < n)
                sum += arr[end];
        }
        else
            sum -= arr[start++];
    }
    return ans;
}