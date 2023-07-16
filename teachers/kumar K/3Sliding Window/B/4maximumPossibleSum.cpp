/*
Given two arrays A and B of size N, the task is to find the maximum sum possible of a window in array B such that elements of the same window in array A are unique.

Example 1:

Input: N = 7
A = [0, 1, 2, 3, 0, 1, 4]
B = [9, 8, 1, 2, 3, 4, 5]
Output: 20
Explanation: The maximum sum possible
in B[] such that all corresponding
elements in A[] are unique is
(9+8+1+2) = 20.


Example 2:

Input: N = 5
A = [0, 1, 2, 0, 2]
B = [5, 6, 7, 8, 2]
Output:  21*/
#include <bits/stdc++.h>
using namespace std;
long int returnMaxSum(int A[], int B[], int n)
{
    // Your code goes here
    long sum = 0, left = 0, right = 0, mx = -1;
    unordered_map<int, int> mp;
    while (right < n)
    {
        sum += B[right];
        mp[A[right]]++;
        while (left <= right && mp[A[right]] > 1)
        {
            sum -= B[left];
            --mp[A[left++]];
        }
        mx = max(mx, sum);
        right++;
    }
    return mx;
}