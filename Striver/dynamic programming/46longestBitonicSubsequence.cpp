/*
Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.
Examples:

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Input arr[] = {12, 11, 40, 5, 3, 1}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

Input arr[] = {80, 60, 30, 40, 20, 10}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)*/

#include <bits/stdc++.h>
using namespace std;
int bitonicSubsequence(vector<int> &arr)
{
    /* this answer here could be:
    1. all increasing- that means no decreasing
    2. all decreasing subseqeunce
    3. the subsequence is first decreasing and then increasing
    4. the subsequence is first increasing and then decreasing

    so, one catch here is the longest decreasing subsequence from any point is longest increasing subsequence from behind

    means if have 2 10 5 0
    then length of longest decreasing from 10 is 3, which is till zero and therefore longest increasing from zero is till 10
    which is of the same length as 3

    therefore to solve this question, we will find the longest increasing subsequence from both front and behind

    we will create the lis array for front and behind till every point which will be then used to find the longest bitonic subseqeunce*/
    int n = arr.size();
    vector<int> lis_front(n, 1), lis_behind(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis_front[i] < lis_front[j] + 1)
                lis_front[i] = lis_front[j] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && lis_behind[i] < lis_behind[j] + 1)
                lis_behind[i] = lis_behind[j] + 1;
        }
    }
    int mx = 1;
    for (int i = 0; i < n; i++)
        mx = max(mx, lis_front[i] + lis_behind[i] - 1);
    return mx;
}
int main()
{
}