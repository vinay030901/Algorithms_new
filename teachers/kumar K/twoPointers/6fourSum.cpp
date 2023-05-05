/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    // Your code goes here
    int n = arr.size();
    vector<vector<int>> ans;
    if (n < 4)
        return ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            for (int k = j + 1, l = n - 1; k < l;)
            {
                long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[k] + (long long)arr[l];
                if (sum == target)
                {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    int first = arr[k], second = arr[l];
                    while (k < l && arr[k] == first)
                        k++;
                    while (k < l && arr[l] == second)
                        l--;
                }
                else if (sum > target)
                    l--;
                else
                    k++;
            }
        }
    }
    return ans;
}