/*
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Example 1:

Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets:
 1 + 2 = 3 and 3 +2 = 5

Example 2:

Input:
N = 3
arr[] = {2, 3, 4}
Output: 0
Explanation: No such triplet exits*/
#include <bits/stdc++.h>
using namespace std;
int countTriplet(int arr[], int n)
{
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        int j = 0, k = i - 1;
        if (i > 2 && arr[i] == arr[i - 1])
            continue;
        while (j < k)
        {
            if (arr[k] + arr[j] == arr[i])
            {
                ans++;
                int first = arr[j], second = arr[j];
                while (j < k && first == arr[j])
                    j++;
                while (j < k && second == arr[k])
                    k--;
            }
            else if (arr[k] + arr[j] > arr[i])
                k--;
            else
                j++;
        }
    }
    return ans;
}