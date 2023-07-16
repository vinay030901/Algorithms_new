/*
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.
Example 1:
Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input :
A[] = {-1, 2, 3}
K = 6
Output : 0
Explanation:
There is no such sub-array with sum 6.*/
#include <bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int arr[], int n, int k)
{
    int sum = 0, mx = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            mx = i + 1;
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
        if (mp.find(sum - k) != mp.end())
        {
            if (mx < i - mp[sum - k])
                mx = i - mp[sum - k];
        }
    }
    return mx;
}
int main()
{

    return 0;
}