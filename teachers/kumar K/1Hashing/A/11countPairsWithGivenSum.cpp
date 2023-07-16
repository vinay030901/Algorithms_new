/*Given an array of N integers, and a number sum, the task is to find the number of pairs of integers in the array whose sum is equal to sum.

Examples:

Input:  arr[] = {1, 5, 7, -1}, sum = 6
Output:  2
Explanation: Pairs with sum 6 are (1, 5) and (7, -1).

Input:  arr[] = {1, 5, 7, -1, 5}, sum = 6
Output:  3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) & (1, 5).


Input:  arr[] = {1, 1, 1, 1}, sum = 2
Output:  6
Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).

Input:  arr[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1}, sum = 11
Output:  9
Explanation: Pairs with sum 11 are (10, 1), (10, 1), (10, 1), (12, -1), (10, 1), (10, 1), (10, 1), (7, 4), (6, 5).*/

#include <bits/stdc++.h>
using namespace std;
int getPairsCount(int arr[], int n, int k)
{
    // code here
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(k - arr[i]) != mp.end())
            ans += mp[k - arr[i]];
        mp[arr[i]]++;
    }
    return ans;
}