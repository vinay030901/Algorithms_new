/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.



Example 1:

Input :
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output :
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Example 2:
Input :
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 */
#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int N, long long int k)
{
    vector<long long> res;
    deque<long long> dq;
    for (long long i = 0; i < N; i++)
    {
        // while (!dq.empty() && arr[dq.back()] <= arr[i])
        //     dq.pop_back();
        if (arr[i] < 0)
            dq.push_back(i);
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        if (i >= k - 1)
            if (dq.empty())
                res.push_back(0);
            else
                res.push_back(arr[dq.front()]);
    }
    return res;
}