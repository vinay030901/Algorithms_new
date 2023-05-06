/*
Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.


Example 1:

Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explaination:
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.*/
#include <bits/stdc++.h>
using namespace std;
int findSubArraySum(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[sum] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp.find(sum - k) != mp.end())
            ans += mp[sum - k];
        mp[sum]++;
    }
    return ans;
}